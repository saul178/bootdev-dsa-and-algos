package stack_test

import (
	"errors"
	"sync"
	"sync/atomic"
	"testing"

	"github.com/saul178/bootdev-dsa-and-algos/dsa/stack"
)

func testGenericStackBehavior[T comparable](t *testing.T, zero T, samples ...T) {
	t.Helper()
	t.Run("New stack is empty", func(t *testing.T) {
		var s = stack.NewStack[T]()
		if !s.IsEmpty() {
			t.Error("new stack should be empty")
		}

		if got := s.Size(); got != 0 {
			t.Errorf("Size is %d, want empty stack", got)
		}
	})

	t.Run("Pop on empty should return zero and an error", func(t *testing.T) {
		var s = stack.NewStack[T]()
		got, err := s.Pop()

		if !errors.Is(err, stack.ErrorStackIsEmpty) {
			t.Errorf("error should be %v, got %v", stack.ErrorStackIsEmpty, err)
		}

		if got != zero {
			t.Errorf("got %v, wanted zero value %v", got, zero)
		}
	})

	t.Run("Peek on empty should return zero and an error", func(t *testing.T) {
		var s = stack.NewStack[T]()
		got, err := s.Peek()

		if !errors.Is(err, stack.ErrorStackIsEmpty) {
			t.Errorf("error should be %v, got %v", stack.ErrorStackIsEmpty, err)
		}

		if got != zero {
			t.Errorf("got %v, wanted zero value %v", got, zero)
		}
	})

	t.Run("Push/Pop is LIFO", func(t *testing.T) {
		var s = stack.NewStack[T]()
		for _, v := range samples {
			s.Push(v)
		}

		if got := s.Size(); got != len(samples) {
			t.Fatalf("Size is %d, want %d", got, len(samples))
		}

		for i := len(samples) - 1; i >= 0; i-- {
			got, err := s.Pop()

			if err != nil {
				t.Errorf("unexpected error %v", err)
			}

			if got != samples[i] {
				t.Errorf("got %v, wanted %v", got, samples[i])
			}
		}

		if !s.IsEmpty() {
			t.Errorf("stack should be empty after popping all items")
		}
	})

	t.Run("Peek does not mutate the stack", func(t *testing.T) {
		var s = stack.NewStack[T]()

		for _, v := range samples {
			s.Push(v)
		}

		prevSize := s.Size()
		got, err := s.Peek()

		if err != nil {
			t.Errorf("unexpected error %v", err)
		}

		if got != samples[len(samples)-1] {
			t.Errorf("Peek() returned %v, wanted %v", got, samples[len(samples)-1])
		}

		if s.Size() != prevSize {
			t.Errorf("Peek() mutated stack: size is %v, previous size was %v", s.Size(), prevSize)
		}
	})
}

type points struct {
	x int
	y int
}

func TestStackStruct(t *testing.T) {
	testGenericStackBehavior(t, points{}, points{1, 2}, points{3, 4}, points{5, 6})
}

func TestStackStrings(t *testing.T) {
	testGenericStackBehavior(t, "", "a", "b", "c", "d", "D", "C", "Hello", "World", "!")
}

func TestStackInts(t *testing.T) {
	testGenericStackBehavior(t, 0, 0, 1, 2, 3, -4, -5, 100, -299, 20)
}

func TestStackPointers(t *testing.T) {
	a := 4
	b := 20
	c := 69
	testGenericStackBehavior(t, nil, &a, &b, &c)
}

func TestStackBools(t *testing.T) {
	testGenericStackBehavior(t, false, true, false, true, false)
}

func TestStackSafeConcurrency(t *testing.T) {
	s := stack.NewStack[int]()
	const goroutines, ops = 20, 2000

	var pushes, pops atomic.Int64
	var wg sync.WaitGroup
	start := make(chan struct{})

	for g := range goroutines {
		wg.Add(1)
		go func(g int) {
			defer wg.Done()
			<-start

			for i := range ops {
				switch (g + i) % 5 {
				case 0:
					s.Push(i)
					pushes.Add(1)
				case 1:
					if _, err := s.Pop(); err == nil {
						pops.Add(1)
					} else if !errors.Is(err, stack.ErrorStackIsEmpty) {
						t.Errorf("Pop() unexpected error: %v", err)
					}
				case 2:
					s.Peek()
				case 3:
					s.Size()
				case 4:
					s.IsEmpty()
				}
			}
		}(g)
	}

	close(start)
	wg.Wait()

	if got, want := s.Size(), int(pushes.Load()-pops.Load()); got != want {
		t.Errorf("size() = %d, want (pushes - pop) = %d", got, want)
	}
}
