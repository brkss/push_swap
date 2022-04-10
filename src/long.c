
#include "../includes/push_swap.h"

static void compare(t_stack *a, t_stack *b)
{
  if(a->stack[0] >= a->metadata.sorted[a->metadata.start] 
      && a->stack[0] <= a->metadata.sorted[a->metadata.end - 1])
  {
    push(a, b);
    if(b->stack[0] > a->metadata.sorted[a->metadata.middle] && b->stack_size > 1)
      rotate(b);
  }
  else 
    rotate(a);
}


void sort_long(t_stack *a, t_stack *b)
{

  int i;

  while(a->stack_size > 0)
  {
    i = a->metadata.end - a->metadata.start;
    while(b->stack_size < i && a->stack_size > 0)
      compare(a, b);
    if(a->metadata.start - a->metadata.offset < 0)
      a->metadata.start = 0;
    else
      a->metadata.start = a->metadata.start - a->metadata.offset;
    if(a->metadata.end + a->metadata.offset > a->metadata.init_size)
      a->metadata.end = a->metadata.init_size;
    else
      a->metadata.end = a->metadata.end + a->metadata.offset;
  }

}
