package sortingalgos;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import org.junit.jupiter.api.Test;

public class BubbleSortTest {
	@Test
	void sortsUnsortedArray() {
		int[] input = { 5, 2, 9, 1, 3 };
		int[] expected = { 1, 2, 3, 5, 9 };
		assertArrayEquals(expected, sortingalgos.SortingAlgos.bubbleSort(input));
	}

	@Test
	void handlesNegatives() {
		int[] input = { 3, -1, 3, 0, -1, -2 };
		assertArrayEquals(new int[] { -2, -1, -1, 0, 3, 3 }, sortingalgos.SortingAlgos.bubbleSort(input));
	}

	@Test
	void handlesEmptyAndSingleValue() {
		int[] emptyInput = {};
		int[] singleInput = { 1 };
		assertArrayEquals(emptyInput, sortingalgos.SortingAlgos.bubbleSort(emptyInput));
		assertArrayEquals(singleInput, sortingalgos.SortingAlgos.bubbleSort(singleInput));
	}
}
