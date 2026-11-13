def merge_sort(nums: list[int]) -> list[int]:
    if len(nums) <= 1:
        return nums

    mid = len(nums) // 2
    left_nums = merge_sort(nums[:mid])
    right_nums = merge_sort(nums[mid:])

    return merge(left_nums, right_nums)

def merge(first: list[int], second: list[int]) -> list[int]:
    sorted_list = []
    i = 0
    j = 0

    while i < len(first) and j < len(second):
        if first[i] <= second[j]:
            sorted_list.append(first[i])
            i += 1
        else:
            sorted_list.append(second[j])
            j += 1
    sorted_list.extend(first[i:])
    sorted_list.extend(second[j:])

    return sorted_list
