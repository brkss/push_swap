


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
void print_stack(t_stack *st);
void exit_with_error();

#endif
