package sortingalgos;

class MergeSort {
	private static int[] merge(int[] leftNums, int[] rightNums) {
		int[] sortedList = new int[] {};
		int i = 0;
		int j = 0;

		while (i < leftNums.length && j < leftNums.length) {
			if (leftNums[i] <= rightNums[j]) {
				sortedList[i] = leftNums[i];
				i++;
			} else {
				sortedList[j] = rightNums[j];
				j++;
			}
		}

		while (i < leftNums.length) {
			sortedList[i] = leftNums[i];
			i++;
		}

		while (j < rightNums.length) {
			sortedList[j] = rightNums[j];
			j++;
		}

		return sortedList;
	}

	public static int[] mergeSort(int[] nums) {
		if (nums.length <= 1) {
			return nums;
		}

		int mid = nums.length / 2;
		int[] leftNums = new int[mid];
		int[] rightNums = new int[nums.length - mid];

		return merge(leftNums, rightNums);

	}

}
