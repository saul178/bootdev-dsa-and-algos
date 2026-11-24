package sortingalgos;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class SelectionSortTest {
	private final SelectionSort ss = new SelectionSort();

	@Test
	void sortsUnsortedArray() {
		int[] input = { 5, 2, 9, 1, 3 };
		int[] expected = { 1, 2, 3, 5, 9 };
		int[] got = ss.selectionSort(input);
		assertArrayEquals(expected, got);
	}

	@Test
	void handlesNegatives() {
		int[] input = { 3, -1, 3, 0, -1, -2 };
		int[] expected = { -2, -1, -1, 0, 3, 3 };
		int[] got = ss.selectionSort(input);
		assertArrayEquals(expected, got);
	}

	@Test
	void handlesEmptyAndSingleValue() {
		int[] emptyInput = {};
		int[] expectEmpty = {};
		int[] got = ss.selectionSort(emptyInput);
		assertArrayEquals(expectEmpty, got);
	}

	@Test
	@DisplayName("testing repeated values")
	void handlesRepeatedValues() {
		int[] input = { 6, 6, 6, 6, 6, 6, 6 };
		int[] expected = { 6, 6, 6, 6, 6, 6, 6 };
		int[] got = ss.selectionSort(input);
		assertArrayEquals(expected, got);
	}
}
