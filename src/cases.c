


#include "../includes/push_swap.h"

void get_case(t_stack *a, t_stack *b){

  (void)b;
  if(a->stack_size < 3)
    handle_two(a);
  else if(a->stack_size == 3)
    handle_three(a);
  else if(a->stack_size == 4 || a->stack_size == 5)
    handle_short(a, b);
  /*
  else if(a->stack_size > 5)
    // handle long !
  */
}

