

#include "../includes/push_swap.h"

void swap(t_stack *stack)
{
  int tmp;

  tmp = stack->stack[0];
  stack->stack[0] = stack->stack[1];
  stack->stack[1] = tmp;
}

static void shift_down(t_stack *stack)
{
  int i;

  i = stack->stack_size - 1;
  while(i > 0)
  {
    stack->stack[i] = stack->stack[i - 1];
    i--;
  }
  stack->stack[0] = 0;
}

static void shift_up(t_stack *stack)
{
  int i;

  i = 0;
  while(i < stack->stack_size -1)
  {
    stack->stack[i] = stack->stack[i + 1];
    i++;
  }
  stack->stack[i] = 0; 
}

// push from stack src to stack dest ;;;
void push(t_stack *src, t_stack *dest)
{
  shift_down(dest);
  dest->stack_size++;
  dest->stack[0] = src->stack[0];
  shift_up(src);
  src->stack_size--;
}
/*
void reverse_rotate(t_stack *dest)
{
  
} 
*/