package sortingalgos;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class QuickSortTest {
	private final QuickSort qs = new QuickSort();

	@Test
	void sortsUnsortedArray() {
		int[] input = { 5, 2, 9, 1, 3 };
		int[] expected = { 1, 2, 3, 5, 9 };
		qs.quickSort(input, 0, input.length - 1);
		assertArrayEquals(expected, input);
	}

	@Test
	void handlesNegatives() {
		int[] input = { 3, -1, 3, 0, -1, -2 };
		int[] expected = { -2, -1, -1, 0, 3, 3 };
		qs.quickSort(input, 0, input.length - 1);
		assertArrayEquals(expected, input);
	}

	@Test
	void handlesEmptyAndSingleValue() {
		int[] emptyInput = {};
		int[] expectEmpty = {};
		int[] singleInput = { 1 };
		int[] singleExpected = { 1 };
		qs.quickSort(emptyInput, 0, emptyInput.length - 1);
		qs.quickSort(singleInput, 0, singleInput.length - 1);
		assertArrayEquals(expectEmpty, emptyInput);
		assertArrayEquals(singleExpected, singleInput);
	}

	@Test
	@DisplayName("testing repeated values")
	void handlesRepeatedValues() {
		int[] input = { 6, 6, 6, 6, 6, 6, 6 };
		int[] expected = { 6, 6, 6, 6, 6, 6, 6 };
		qs.quickSort(input, 0, input.length - 1);
		assertArrayEquals(expected, input);
	}
}
