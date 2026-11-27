#include "stack.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  int *items;
  size_t count;
  size_t capacity;
  pthread_mutex_t lock;
};

Stack *stack_create(size_t initial_capacity) {
  Stack *new_stack = malloc(sizeof(Stack));
  if (new_stack == NULL) {
    return NULL;
  }

  new_stack->items = malloc(initial_capacity * sizeof(new_stack->items));
  if (new_stack->items == NULL) {
    return NULL;
  }

  return new_stack;
}

void stack_destroy(Stack *s) {
  if (s->items != NULL) {
    free(s->items);
  }

  if (s != NULL) {
    free(s);
  }
}
