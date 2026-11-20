package sortingalgos;

class MergeSort {
	// split original array to two halfs
	public static int[] mergeSort(int[] nums, int n) {
		if (n <= 1) {
			return nums;
		}

		int mid = n / 2;
		int[] leftArr = new int[mid];
		int[] rightArr = new int[n - mid];

		for (int i = 0; i < mid; ++i) {
			leftArr[i] = nums[i];
		}

		for (int i = mid; i < n; ++i) {
			rightArr[i - mid] = nums[i];
		}

		mergeSort(leftArr, mid);
		mergeSort(rightArr, n - mid);

		return merge(nums, leftArr, rightArr, mid, n - mid);
	}

	// main sorting happens here
	public static int[] merge(int[] nums, int[] leftArr, int[] rightArr, int leftN, int rightN) {
		int i = 0;
		int j = 0;
		int k = 0;

		while (i < leftN && j < rightN) {
			if (leftArr[i] <= rightArr[j]) {
				nums[k++] = leftArr[i++];
			} else {
				nums[k++] = rightArr[j++];
			}
		}

		while (i < leftN) {
			nums[k++] = leftArr[i++];
		}

		while (j < leftN) {
			nums[k++] = rightArr[j++];
		}

		return nums;
	}
}
