package main

func BinarySearch(target int, nums []int) bool {
	low_bound := 0
	high_bound := len(nums) - 1

	for low_bound <= high_bound {
		mid := high_bound + (low_bound - high_bound) / 2
		if nums[mid] == target {
			return true
		} else if nums[mid] < target {
			low_bound = mid + 1
		} else {
			high_bound = mid - 1
		}
	}
	return false
}
