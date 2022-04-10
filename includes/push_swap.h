


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_metadata {
  int *sorted;
  int offset;
  int middle;
  int start;
  int end;
  int init_size;
  int dawn;
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
void plot_metadata(t_stack *a);

// actions 
void swap(t_stack *stack);
void push(t_stack *src, t_stack *dest);
void reverse_rotate(t_stack *dest);
void rotate(t_stack *dest);

// sort 
void handle_three(t_stack *dest);
void handle_two(t_stack *dest);
void handle_short(t_stack *a, t_stack *b);
void sort_long(t_stack *a, t_stack *b);

// long sort 
void init_data(t_stack *a);

#endif
