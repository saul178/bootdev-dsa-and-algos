package sortingalgos;

class QuickSort {
	private int partition(int nums[], int low, int high) {
		int pivot = high;
		int i = low - 1;
		int tmp;

		for (int j = low; j < high; ++j) {
			if (nums[j] < nums[pivot]) {
				i++;
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}

		tmp = nums[i + 1];
		nums[i + 1] = nums[pivot];
		nums[pivot] = tmp;
		return i + 1;
	}

	public void quickSort(int nums[], int low, int high) {
		if (low < high) {
			int p = partition(nums, low, high);
			quickSort(nums, low, p - 1);
			quickSort(nums, p + 1, high);
		}
	}
}
