


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_metadata {
  int min;
  int max;
} t_metadata;

typedef struct s_stack {
  int *stack;
  int stack_size;
  t_metadata metadata;
} t_stack;


int check_parameters(int count, char **args);

#endif
