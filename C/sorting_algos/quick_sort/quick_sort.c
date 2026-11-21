#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

typedef enum {
  INFO,
  ERROR,
  DEBUG,
} Log;

void print_array(Log msg_type, const char *msg, int *nums, size_t nums_len) {
  if (msg != NULL) {
    switch (msg_type) {
    case INFO:
      printf("[INFO] %s", msg);
      break;
    case ERROR:
      printf("[ERROR] %s", msg);
      break;
    case DEBUG:
      printf("[DEBUG] %s", msg);
      break;
    }
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

int partition(int *nums, int low, int high) {
  int pivot = high;
  int i = low - 1;

  for (int j = low; j < high; ++j) {
    if (nums[j] < nums[pivot]) {
      i++;
      swap(&nums[j], &nums[i]);
    }
  }

  swap(&nums[i + 1], &nums[pivot]);
  return i + 1;
}

void quick_sort(int *nums, int low, int high) {
  if (low < high) {
    int p = partition(nums, low, high);
    quick_sort(nums, low, p - 1);
    quick_sort(nums, p + 1, high);
  }
}

int test_quick_sort(const char *name, int *input, int input_len, int *expected,
                    int expected_len) {
  if (input_len != expected_len) {
    printf("[ERROR] %s arrays aren't equal size exiting...", name);
    return EXIT_FAILURE;
  }

  quick_sort(input, 0, input_len - 1);
  if (!equal_arrays(input, expected, input_len, expected_len)) {
    printf("%s", name);
    print_array(ERROR, "Test FAILED\n", input, input_len);
    print_array(ERROR, NULL, expected, expected_len);
    return EXIT_FAILURE;
  } else {
    printf("Test %s\n", name);
    print_array(INFO, "Test PASSED!\n", input, input_len);
    print_array(INFO, NULL, expected, expected_len);
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
  int tests_len = sizeof(tests) / sizeof(tests[0]);

  for (int i = 0; i < tests_len; ++i) {
    printf("-----------------------------------------------\n");
    test_quick_sort(tests[i].name, tests[i].input, tests[i].len,
                    tests[i].expected, tests[i].len);
    printf("-----------------------------------------------\n");
  }

  return 0;
}
