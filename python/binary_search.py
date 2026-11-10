def binary_search(target: int, arr: list[int]) -> bool:
    low_bound = 0
    high_bound = len(arr) - 1

    while low_bound <= high_bound:
        mid = high_bound - (low_bound + high_bound) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            low_bound = mid + 1
        else:
            high_bound = mid - 1
    return False

