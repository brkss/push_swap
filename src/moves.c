

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
  dest->stack_size++;
  shift_down(dest);
  dest->stack[0] = src->stack[0];
  shift_up(src);
  src->stack_size--;
}

void rotate(t_stack *dest)
{
  int i;
  int tmp;

  tmp = dest->stack[0];
  i = 1;
  while(i < dest->stack_size)
  {
    dest->stack[i - 1] = dest->stack[i];
    i++;
  }
  dest->stack[dest->stack_size - 1] = tmp;
}

void reverse_rotate(t_stack *dest)
{
  int i;
  int tmp;

  i = dest->stack_size - 1;
  if(i < 0)
    return;
  tmp = dest->stack[i];
  while(i > 0)
  {
    dest->stack[i] = dest->stack[i - 1];
    i--;
  }
  dest->stack[0] = tmp;
} 

