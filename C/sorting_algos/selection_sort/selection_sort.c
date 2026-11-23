#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

bool equal_arrays(int *arr1, int *arr2, size_t arr1_len, size_t arr2_len) {
  if (arr1_len != arr2_len) {
    return false;
  }

  for (size_t i = 0; i < arr1_len; ++i) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}

void print_arrays(const char *name, int *nums, size_t nums_len) {
  if (name != NULL) {
    printf("%s\n", name);
  }
  printf("[");

  for (size_t i = 0; i < nums_len; ++i) {
    printf("%d", nums[i]);
    if (i < nums_len - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int *selection_sort(int *nums, size_t nums_len) {
  for (size_t i = 0; i < nums_len; ++i) {
    size_t smallest_idx = i;
    for (size_t j = i + 1; j < nums_len; ++j) {
      if (nums[j] < nums[smallest_idx]) {
        smallest_idx = j;
      }
    }
    swap(&nums[i], &nums[smallest_idx]);
  }
  return nums;
}

int test_selection_sort(const char *name, int *input, size_t input_len,
                        int *expected, size_t expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] %s arrays aren't equal size exiting...", name);
    return EXIT_FAILURE;
  }

  selection_sort(input, input_len);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("%s", name);
    print_arrays("Test FAILED\n", input, input_len);
    print_arrays(NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("Test %s\n", name);
    print_arrays("Test PASSED!\n", input, input_len);
    print_arrays(NULL, expected, expected_len);
    return EXIT_SUCCESS;
  }
}

typedef struct {
  const char *name;
  int input[MAX_LEN];
  int expected[MAX_LEN];
  size_t len;
} TestCase;

int main() {
  TestCase test_cases[4] = {{
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
  int tests_len = sizeof(test_cases) / sizeof(test_cases[0]);

  for (int i = 0; i < tests_len; ++i) {
    printf("-----------------------------------------------\n");
    test_selection_sort(test_cases[i].name, test_cases[i].input,
                        test_cases[i].len, test_cases[i].expected,
                        test_cases[i].len);
    printf("-----------------------------------------------\n");
  }

  return 0;
}
