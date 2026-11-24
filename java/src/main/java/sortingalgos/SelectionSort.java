package sortingalgos;

class SelectionSort {
	public int[] selectionSort(int[] nums) {
		for (int i = 0; i < nums.length; ++i) {
			int smallestIdx = i;
			for (int j = i + 1; j < nums.length; ++j) {
				if (nums[j] < nums[smallestIdx]) {
					smallestIdx = j;
				}
			}

			int tmp = nums[i];
			nums[i] = nums[smallestIdx];
			nums[smallestIdx] = tmp;
		}
		return nums;
	}
}
