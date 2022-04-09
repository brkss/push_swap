

#include "../includes/push_swap.h"


void handle_two(t_stack *dest){
  if(dest->stack_size == 1)
    exit(0);
  if(dest->stack[0] > dest->stack[1]){
    rotate(dest);
    exit(0);
  }
  else
    exit(0);
}

static int is_tree_sorted(t_stack *dest)
{
  return (dest->stack[0] < dest->stack[1] && dest->stack[1] < dest->stack[2]);
}

void handle_three(t_stack *dest)
{
  while(!is_tree_sorted(dest))
  {
    if(dest->stack[0] > dest->stack[1] && dest->stack[1] < dest->stack[2] && dest->stack[0] > dest->stack[2])
      rotate(dest);
    if(dest->stack[0] < dest->stack[1] && dest->stack[1] > dest->stack[2] && dest->stack[0] > dest->stack[2])
      reverse_rotate(dest);
    if(dest->stack[0] > dest->stack[1] || (dest->stack[0] < dest->stack[1] && dest->stack[2] < dest->stack[1]))
      swap(dest);
  }
}
