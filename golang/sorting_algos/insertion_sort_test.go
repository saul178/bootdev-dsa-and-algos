package sortingalgos

import (
	"slices"
	"testing"
)

func TestInsertionSort(t *testing.T) {
	testCases := []struct {
		name     string
		input    []int
		expected []int
	}{
		{
			name:     "test unsorted list of numbers",
			input:    []int{5, 7, 3, 6, 8},
			expected: []int{3, 5, 6, 7, 8},
		},
		{
			name:     "test small set of numbers",
			input:    []int{2, 1},
			expected: []int{1, 2},
		},
		{
			name:     "test unsorted list of numbers w/ negatives",
			input:    []int{10, -2, 32, 32, 0, 1},
			expected: []int{-2, 0, 1, 10, 32, 32},
		},
		{
			name:     "test empty list of numbers",
			input:    []int{},
			expected: []int{},
		},
		{
			name:     "test single value",
			input:    []int{1},
			expected: []int{1},
		},
		{
			name:     "test repeated numbers",
			input:    []int{7, 7, 7, 7, 7},
			expected: []int{7, 7, 7, 7, 7},
		},
	}

	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			got := insertionSort(tt.input)

			if !slices.Equal(got, tt.expected) {
				t.Errorf("[ERROR] Test %s failed\ngot %v, wanted %v", tt.name, got, tt.expected)
			}
		})
	}
}
