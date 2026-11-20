package sortingalgos

func insertionSort(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		j := i
		for j > 0 && nums[j-1] >= nums[j] {
			nums[j-1], nums[j] = nums[j], nums[j-1]
			j--
		}
	}
	return nums
}
