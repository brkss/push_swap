

#include "../includes/push_swap.h"


void print_stacks(t_stack *a, t_stack *b)
{

  int i;
  int j;
  
  i = 0;
  j = 0;
  printf("\n --------------------------- \n");
  while(i < a->stack_size || j < b->stack_size)
  {
    if(i < a->stack_size){
      printf("%d ", a->stack[i]);
    }
    printf("\t");
    if(j < b->stack_size){
      printf(" %d", b->stack[j]);
    }
    printf("\n");
    i++;
    j++;
  }

  printf("-- \t -- \n");
  printf("a  \t b  \n");
  printf("\n --------------------------- \n");
}
