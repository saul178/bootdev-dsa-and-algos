package main

func BubbleSort(nums []int) []int {
	swap := true
	end := len(nums)

	for swap {
		swap = false
		for i := 1; i < end; i++ {
			if nums[i-1] > nums[i] {
				nums[i], nums[i-1] = nums[i-1], nums[i]
				swap = true
			}
		}
	}
	return nums

}
