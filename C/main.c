#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool binary_search(int target, int nums_list[], size_t nums_len) {
  size_t low_bound = 0;
  size_t high_bound = nums_len - 1;

  while (low_bound <= high_bound) {
    size_t mid = high_bound + (low_bound - high_bound) / 2;
    if (nums_list[mid] == target) {
      return true;
    }
    else if (nums_list[mid] > target) {
      low_bound = mid + 1;
    } else {
      high_bound = mid - 1;
    }
  }
  return false;
}

int main(void) {
  int nums_list[] = {1,2,3,4,5,6,7,8,9};
  size_t nums_len = sizeof(nums_list) / sizeof(nums_list[0]);
  printf("%s\n", binary_search(5, nums_list, nums_len) ? "true": "false");
}
