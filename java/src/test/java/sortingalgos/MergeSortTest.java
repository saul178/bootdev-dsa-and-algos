package sortingalgos;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class MergeSortTest {
	@Test
	@DisplayName("empty array")
	void handleEmptyValues() {
		int[] input = {};
		int[] expected = {};
		assertArrayEquals(expected, sortingalgos.MergeSort.mergeSort(input, input.length));
	}

	@Test
	@DisplayName("sigle value array")
	void handleSingleValue() {
		int[] input = { 1 };
		int[] expected = { 1 };
		assertArrayEquals(expected, sortingalgos.MergeSort.mergeSort(input, input.length));
	}

	@Test
	@DisplayName("unsorted list with negatives")
	void handleUnsortedList() {
		int[] input = { 4, -7, 1, 0, 5 };
		int[] expected = { -7, 0, 1, 4, 5 };
		assertArrayEquals(expected, sortingalgos.MergeSort.mergeSort(input, input.length));
	}
}
