package sortingalgos

func selectionSort(nums []int) []int {
	for i := range nums {
		smallestIdx := i
		for j := i + 1; j < len(nums); j++ {
			if nums[j] < nums[smallestIdx] {
				smallestIdx = j
			}
		}
		nums[i], nums[smallestIdx] = nums[smallestIdx], nums[i]
	}
	return nums
}
