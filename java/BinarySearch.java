class BinarySearch {
	public static boolean binarySearch(int target, int[] nums) {
		Integer lowBound = 0;
		Integer highBound = nums.length - 1;

		while (lowBound <= highBound) {
			Integer mid = highBound - (lowBound + highBound) / 2;
			if (nums[mid] == target) {
				return true;
			} else if (nums[mid] < target) {
				lowBound = mid + 1;
			} else {
				highBound = mid - 1;
			}
		}
		return false;
	}
}
