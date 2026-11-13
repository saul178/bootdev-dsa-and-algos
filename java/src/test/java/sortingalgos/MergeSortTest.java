package sortingalgos;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import org.junit.jupiter.api.Test;

public class MergeSortTest {
	@Test
	void handleEmptyValues() {
		int[] input = {};
		int[] expected = {};
		assertArrayEquals(expected, sortingalgos.MergeSort.mergeSort(input));
	}

	@Test
	void handleSingleValue() {
		int[] input = { 1 };
		int[] expected = { 1 };
		assertArrayEquals(expected, sortingalgos.MergeSort.mergeSort(input));
	}

	@Test
	void handleUnsortedList() {
		int[] input = { 4, -7, 1, 0, 5 };
		int[] expected = { -7, 0, 1, 4, 5 };
		int[] actual = sortingalgos.MergeSort.mergeSort(input);
		assertArrayEquals(expected, actual);
	}
}
