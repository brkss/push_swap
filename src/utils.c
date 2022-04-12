
#include "../includes/push_swap.h"

static int offset(t_stack *a) 
{
  if(a->stack_size <= 10)
    return a->stack_size / 2;
  else if(a->stack_size <= 150)
    return a->stack_size / 8;
  else 
    return a->stack_size / 18;
}

void init_data(t_stack *a)
{
  a->metadata.init_size = a->stack_size;
  a->metadata.offset = offset(a);
  a->metadata.middle = a->stack_size / 2;
  a->metadata.start = a->metadata.middle  - a->metadata.offset;
  a->metadata.end = a->metadata.middle  + a->metadata.offset;
}

void put_str(char *str)
{
  if(!str && 0)
    return;
  while(*str)
  {
    write(1, str, 1);
    str++;
  }
}