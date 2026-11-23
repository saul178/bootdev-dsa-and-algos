package sortingalgos

import (
	"slices"
	"testing"
)

func TestSelectionSort(t *testing.T) {
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
			got := selectionSort(tt.input)
			if !slices.Equal(got, tt.expected) {
				t.Errorf("[ERROR] %s FAILED:\ngot %v, wanted %v", tt.name, got, tt.expected)
			}
		})

	}
}
