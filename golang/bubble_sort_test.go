package main

import (
	"fmt"
	"slices"
	"testing"
)

func TestBubbleSort(t *testing.T) {
	testCases := []struct {
		name     string
		input    []int
		expected []int
	}{
		{
			name:     "test unsorted list",
			input:    []int{4, 1, 5, 76, 2, 1, 7},
			expected: []int{1, 1, 2, 4, 5, 7, 76},
		},
		{
			name:     "test with negative values",
			input:    []int{1, 5, -2, -4, 8, -1, 0},
			expected: []int{-4, -2, -1, 0, 1, 5, 8},
		},
		{
			name:     "test empty arrays",
			input:    []int{},
			expected: []int{},
		},
		{
			name:     "test 1 value array",
			input:    []int{2},
			expected: []int{2},
		},
	}

	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			result := BubbleSort(tt.input)
			if !slices.Equal(result, tt.expected) {
				fmt.Println("---------------------------------------")
				t.Errorf("got %v, want %v", result, tt.expected)
			}
		})

	}
}
