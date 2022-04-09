


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_metadata {
  int min;
  int max;
  int *sorted;
} t_metadata;

typedef struct s_stack {
  int *stack;
  int stack_size;
  t_metadata metadata;
} t_stack;


int check_parameters(int count, char **args);
int ft_atoi(const char *str);
void fill_stack(t_stack *a, int count, char **args);
void exit_with_error();
int *sort(t_stack *a);
void is_sorted(t_stack *a);
void get_case(t_stack *a, t_stack *b);

// print
void print_stacks(t_stack *a, t_stack *b);

// actions 
void swap(t_stack *stack);
void push(t_stack *src, t_stack *dest);
void reverse_rotate(t_stack *dest);
void rotate(t_stack *dest);

#endif
