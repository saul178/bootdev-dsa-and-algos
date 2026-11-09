#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
bool find_minimum(const int num[], size_t arr_len, int *min) {
  if (num == NULL || min == NULL || arr_len == 0) {
    return false;
  }

  int minimum = num[0];
  for (size_t i = 1; i < arr_len; ++i) {
    if (num[i] < minimum) {
      minimum = num[i];
    }
  }

  *min = minimum;
  return true;
}

typedef enum {
  OTHER = -1,
  FITNESS_INFLUENCER,
  COSMETIC_INFLUENCER,
} InfluencerType;

InfluencerType get_influencer_type(const char *str) {
  if (strcmp(str, "fitness") == 0) {
    return FITNESS_INFLUENCER;
  }
  if (strcmp(str, "cosmetic") == 0) {
    return COSMETIC_INFLUENCER;
  }
  return OTHER;
}

int get_follower_prediction(int follower_count, const char *infuencer_type,
                            int num_months) {

  switch (get_influencer_type(infuencer_type)) {
  case FITNESS_INFLUENCER:
    follower_count = (follower_count)*pow(4, num_months);
    break;
  case COSMETIC_INFLUENCER:
    follower_count = (follower_count)*pow(3, num_months);
    break;
  case OTHER:
    follower_count = (follower_count)*pow(2, num_months);
    break;
  }
  return follower_count;
}

int main(void) {
  int num[] = {10, 11, 12, 5, 14, 15};
  size_t arr_len = sizeof(num) / sizeof(num[0]);

  int min;
  if (find_minimum(num, arr_len, &min)) {
    printf("%d\n", min);
  } else {
    fprintf(stderr, "empty array\n");
  }
  return 0;
}
