

#include "../includes/push_swap.h"


void fill_stack(t_stack *a, int count, char **args){

  int i;
  int j;

  if(!a || !args || count == 0)
    return;
  i = 0;
  j = 1;
  while(i < count - 1){
    a->stack[i] = ft_atoi(args[j]);
    i++;
    j++;
  }
  return;
}

void print_stack(t_stack *st){


  int i;

  i = 0;
  while(i < st->stack_size){
    printf("STACK[%d] = %d \n", i, st->stack[i]);
    i++;
  }

}
