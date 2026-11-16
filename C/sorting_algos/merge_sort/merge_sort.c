#include "merge_sort.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool equal_arrays(const int *arr1, const int *arr2, size_t arr1_len,
                  size_t arr2_len) {
  if (arr1_len != arr2_len) {
    return false;
  }

  size_t i = 0;
  size_t j = 0;
  while (i < arr1_len && j < arr2_len) {
    if (arr1[i] != arr2[j]) {
      return false;
    }
    i++;
    j++;
  }
  return true;
}

void print_array(const char *str, const int *arr, size_t len) {
  if (str != NULL) {
    printf("%s", str);
  }

  printf("[");
  for (size_t i = 0; i < len; ++i) {
    printf("%d", arr[i]);
    if (i < len - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

void merge(int *og_nums, size_t mid, size_t nums_len, int *scratch) {
  assert(0 < mid && mid < nums_len);
  size_t left_n = mid;
  size_t right_n = nums_len - mid;

  for (size_t i = 0; i < left_n; ++i) {
    scratch[i] = og_nums[i];
  }

  for (size_t i = left_n; i < nums_len; ++i) {
    scratch[i] = og_nums[i];
  }

  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  while (i < left_n && j < right_n) {
    if (scratch[i] <= scratch[left_n + j]) {
      og_nums[k] = scratch[i];
      i++;
    } else {
      og_nums[k] = scratch[left_n + j];
      j++;
    }
    k++;
  }

  while (i < left_n) {
    og_nums[k] = scratch[i];
    i++;
    k++;
  }

  while (j < right_n) {
    og_nums[k] = scratch[left_n + j];
    j++;
    k++;
  }
}

static void merge_sort_rec(int *nums, size_t nums_len, int *scratch) {
  if (nums_len < 2) {
    return;
  }

  size_t mid = nums_len / 2;
  merge_sort_rec(nums, mid, scratch);
  merge_sort_rec(nums + mid, nums_len - mid, scratch);
  merge(nums, mid, nums_len, scratch);
}

bool merge_sort(int *nums, size_t nums_len) {
  if (nums_len < 2) {
    return true;
  }

  int *scratch = malloc(nums_len * sizeof(*scratch));
  if (scratch == NULL) {
    return false;
  }

  merge_sort_rec(nums, nums_len, scratch);
  free(scratch);
  return true;
}

int test_merge_sort(int *input, int *expected, size_t input_len,
                    size_t expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] arrays aren't equal size exiting...");
    return EXIT_FAILURE;
  }

  merge_sort(input, input_len);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("[ERROR] test failed array values are not equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("[INFO] test passed! Arrays are equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_SUCCESS;
  }
}

int test_empty_array(int *input, int *expected, size_t input_len,
                     size_t expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] arrays aren't equal size exiting...");
    return EXIT_FAILURE;
  }

  merge_sort(input, input_len);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("[ERROR] test failed array values are not equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("[INFO] test passed! Arrays are equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_SUCCESS;
  }
}

int test_single_value(int *input, int *expected, size_t input_len,
                      size_t expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] arrays aren't equal size exiting...");
    return EXIT_FAILURE;
  }

  merge_sort(input, input_len);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("[ERROR] test failed array values are not equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("[INFO] test passed! Arrays are equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_SUCCESS;
  }
}

int test_repeated_values(int *input, int *expected, size_t input_len,
                         size_t expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] arrays aren't equal size exiting...");
    return EXIT_FAILURE;
  }

  merge_sort(input, input_len);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("[ERROR] test failed array values are not equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("[INFO] test passed! Arrays are equal\n");
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_SUCCESS;
  }
}

int main() {
  printf(
      "\n----------------------------------------------------------------\n");
  int test_arr[] = {-10, 20, 0, 1, 2, 2, -3, 400, -400};
  int correct_arr[] = {-400, -10, -3, 0, 1, 2, 2, 20, 400};
  size_t test_arr_len = sizeof(test_arr) / sizeof(test_arr[0]);
  size_t correct_arr_len = sizeof(correct_arr) / sizeof(correct_arr[0]);
  test_merge_sort(test_arr, correct_arr, test_arr_len, correct_arr_len);

  printf(
      "\n----------------------------------------------------------------\n");
  int empty_arr_test[] = {};
  int correct_empty_arr[] = {};
  size_t empty_arr_len = sizeof(empty_arr_test) / sizeof(empty_arr_test[0]);
  size_t correct_empty_len =
      sizeof(correct_empty_arr) / sizeof(correct_empty_arr[0]);
  test_empty_array(empty_arr_test, correct_arr, empty_arr_len,
                   correct_empty_len);

  printf(
      "\n----------------------------------------------------------------\n");
  int single_value[1] = {1};
  int correct_single_value[1] = {1};
  size_t single_len = sizeof(single_value) / sizeof(single_value[0]);
  size_t correct_single_len =
      sizeof(correct_single_value) / sizeof(correct_single_value[0]);
  test_single_value(single_value, correct_single_value, single_len,
                    correct_single_len);

  printf(
      "\n----------------------------------------------------------------\n");
  int repeated_nums[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
  int correct_repeated_nums[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
  size_t repeated_nums_len = sizeof(repeated_nums) / sizeof(repeated_nums[0]);
  size_t correct_repeated_nums_len =
      sizeof(correct_repeated_nums) / sizeof(correct_repeated_nums[0]);
  test_repeated_values(repeated_nums, correct_repeated_nums, repeated_nums_len,
                       correct_repeated_nums_len);
}
