package sortingalgos

func partition(nums []int, low int, high int) int {
	pivot := high
	i := low - 1

	for j := low; j < high; j++ {
		if nums[j] < nums[pivot] {
			i++
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	nums[i+1], nums[high] = nums[high], nums[i+1]
	return i + 1
}

func quickSort(nums []int, low int, high int) {
	if low < high {
		p := partition(nums, low, high)
		quickSort(nums, low, p-1)
		quickSort(nums, p+1, high)
	}
}
