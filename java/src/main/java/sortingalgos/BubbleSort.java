package sortingalgos;

class SortingAlgos {
	public static int[] bubbleSort(int[] nums) {
		boolean swapping = true;
		int end = nums.length;

		while (swapping) {
			swapping = false;
			for (int i = 1; i < end; ++i) {
				if (nums[i - 1] > nums[i]) {
					int tmp = nums[i - 1];
					nums[i - 1] = nums[i];
					nums[i] = tmp;
					swapping = true;
				}
			}
		}
		return nums;
	}
}
