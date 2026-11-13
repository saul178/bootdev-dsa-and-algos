package main

func mergeSort(nums []int) []int {
	if len(nums) <= 1 {
		return nums
	}

	mid := len(nums) / 2
	leftNums := mergeSort(nums[:mid])
	rightNums := mergeSort(nums[mid:])
	return merge(leftNums, rightNums)
}

func merge(leftNums []int, rightNums []int) []int {
	sortedList := []int{}
	i := 0
	j := 0

	for i < len(leftNums) && j < len(rightNums) {
		if leftNums[i] <= rightNums[j] {
			sortedList = append(sortedList, leftNums[i])
			i++
		} else {
			sortedList = append(sortedList, rightNums[j])
			j++
		}
	}

	for i < len(leftNums) {
		sortedList = append(sortedList, leftNums[i])
		i++
	}

	for j < len(rightNums) {
		sortedList = append(sortedList, rightNums[j])
		j++
	}

	return sortedList

}
