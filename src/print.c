

#include "../includes/push_swap.h"


void print_stacks(t_stack *a, t_stack *b)
{

  int i;
  int j;
  
  i = 0;
  j = 0;
  if(1)
  {

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
}

void plot_metadata(t_stack *a)
{
  printf("MIDDLE : %d\n", a->metadata.middle);
  printf("END : %d\n", a->metadata.end);
  printf("START : %d\n", a->metadata.start);
  printf("INIT_SIZE : %d\n", a->metadata.init_size);
  printf("OFFSET : %d\n", a->metadata.offset);
  printf("DAWN : %d\n", a->metadata.dawn);
}
