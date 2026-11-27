#ifndef STACK_H
#define STACK_H
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>

// Stack struct will hold int *items, int count to keep track of it's current
// size, int capacity to know the upper limit of the stack so that we can double
// the capacity and reallocate,
// pthread_mutex_t lock; to make the stack concurrent safe.
typedef struct Stack Stack;

// create a new stack returns null on failure
Stack *stack_create(size_t initial_capacity);

// frees up the memory used from the stack
void stack_destroy(Stack *s);

size_t stack_size(Stack *s);
bool stack_is_empty(Stack *s);

// returns false if allocation failed when growing capacity should increase if
// implemented correctly
bool stack_push(Stack *s, int item);

// assigns the item to *out and removes it. returns false if the stack is empty
// indicating a error
bool stack_pop(Stack *s, int *out);

// assigns the item to *out without removing it. returns false if the stack is
// empty indicating a error
bool stack_peek(Stack *s, int *out);
#endif
