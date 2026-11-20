package sortingalgos

import (
	"slices"
	"testing"
)

func TestQuickSort(t *testing.T) {
	testCases := []struct {
		name     string
		input    []int
		expected []int
	}{
		{
			name:     "empty array",
			input:    []int{},
			expected: []int{},
		},
		{
			name:     "single element",
			input:    []int{1},
			expected: []int{1},
		},
		{
			name:     "all equal",
			input:    []int{7, 7, 7, 7, 7, 7, 7, 7, 7},
			expected: []int{7, 7, 7, 7, 7, 7, 7, 7, 7},
		},
		{
			name:     "unsorted odd length",
			input:    []int{5, 2, 9, 1, 7},
			expected: []int{1, 2, 5, 7, 9},
		},
		{
			name:     "unsorted with negatives",
			input:    []int{10, 2, -3, 40, -100, 2000, 69, -420},
			expected: []int{-420, -100, -3, 2, 10, 40, 69, 2000},
		},
	}

	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			quickSort(tt.input, 0, len(tt.input) - 1)
			if !slices.Equal(tt.input, tt.expected) {
				t.Errorf("test failed got: %v, expected %v", tt.input, tt.expected)
			}
		})

	}
}
