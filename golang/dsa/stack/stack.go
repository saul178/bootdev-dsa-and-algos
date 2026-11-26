package stack

import (
	"errors"
	"sync"
)

// goal: make it generic, make concurrent safe.

var ErrorStackIsEmpty = errors.New("Stack is Empty")

type Stack[T any] struct {
	items []T
	mu    sync.Mutex
}

func NewStack[T any]() *Stack[T] {
	return &Stack[T]{items: []T{}}
}

func (s *Stack[T]) Size() int {
	s.mu.Lock()
	defer s.mu.Unlock()

	return len(s.items)
}

func (s *Stack[T]) IsEmpty() bool {
	s.mu.Lock()
	defer s.mu.Unlock()

	return len(s.items) == 0
}

func (s *Stack[T]) Push(item T) {
	s.mu.Lock()
	defer s.mu.Unlock()

	s.items = append(s.items, item)
}

func (s *Stack[T]) Pop() (T, error) {
	s.mu.Lock()
	defer s.mu.Unlock()

	var zero T
	if len(s.items) == 0 {
		return zero, ErrorStackIsEmpty
	}

	item := s.items[len(s.items)-1]
	s.items[len(s.items)-1] = zero
	s.items = s.items[:len(s.items)-1]

	return item, nil
}

func (s *Stack[T]) Peek() (T, error) {
	s.mu.Lock()
	defer s.mu.Unlock()

	var zero T
	if len(s.items) == 0 {
		return zero, ErrorStackIsEmpty
	}

	return s.items[len(s.items)-1], nil
}
