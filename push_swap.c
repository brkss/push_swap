

#include "./includes/push_swap.h"


int main(int argc, char ** argv){


  t_stack  *a;
  t_stack  *b;

  if(argc > 1){
    
    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    a->stack = (int *)malloc(sizeof(int) * argc - 1);
    b->stack = (int *)malloc(sizeof(int) * argc - 1);

    if(!check_parameters(argc, argv)){
      printf("\nError");
      exit(0);
    }

    printf("PASSED !");
    return (0);
  }

}
