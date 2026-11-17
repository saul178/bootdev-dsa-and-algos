#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

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

int *insertion_sort(int *nums, size_t nums_len) {
  for (size_t i = 1; i < nums_len; ++i) {
    size_t j = i;
    while (j > 0 && nums[j - 1] >= nums[j]) {
      int tmp = nums[j - 1];
      nums[j - 1] = nums[j];
      nums[j] = tmp;
      j--;
    }
  }
  return nums;
}

int test_insertion_sort(const char *name, int *input, size_t input_len,
                        int *expected, size_t expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] %s arrays aren't equal size exiting...", name);
    return EXIT_FAILURE;
  }

  insertion_sort(input, input_len);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("[ERROR] test %s failed array values are not equal\n", name);
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("[INFO] test %s passed! Arrays are equal and sorted\n", name);
    print_array(NULL, input, input_len);
    print_array(NULL, expected, expected_len);
    return EXIT_SUCCESS;
  }
}

typedef struct {
  const char *name;
  int input[MAX_LEN];
  int expected[MAX_LEN];
  int len;
} TestCases;

int main() {
  TestCases tests[] = {{
                           .name = "repeated values",

                           .input = {10, 10, 10, 10, 10, 10},
                           .expected = {10, 10, 10, 10, 10, 10},
                           .len = 6,
                       },
                       {
                           .name = "single value",
                           .input = {10},
                           .expected = {10},
                           .len = 1,

                       },
                       {
                           .name = "unsorted values with negatives",
                           .input = {10, -2, 32, 32, 0, 1},
                           .expected = {-2, 0, 1, 10, 32, 32},
                           .len = 6,

                       },
                       {
                           .name = "empty value",
                           .input = {},
                           .expected = {},
                           .len = 0,
                       }};
  size_t tests_len = sizeof(tests) / sizeof(tests[0]);

  for (size_t i = 0; i < tests_len; ++i) {
    printf("-----------------------------------------------\n");
    test_insertion_sort(tests[i].name, tests[i].input, tests[i].len,
                        tests[i].expected, tests[i].len);
    printf("-----------------------------------------------\n");
  }

  return 0;
}
