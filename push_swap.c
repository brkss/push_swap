

#include "./includes/push_swap.h"


int main(int argc, char ** argv){


  t_stack  *a;
  t_stack  *b;

  if(argc > 1){
    
    if(!check_parameters(argc, argv)){
      printf("\nError");
      exit(0);
    }
    
    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    a->stack = (int *)malloc(sizeof(int) * argc - 1);
    b->stack = (int *)malloc(sizeof(int) * argc - 1);
    a->stack_size = argc - 1;
    b->stack_size = 0;
    
    fill_stack(a, argc, argv);
    print_stack(a);

    a->metadata.sorted = sort(a);
    int i = 0;
    while(i < a->stack_size){
      printf("%d\n", a->metadata.sorted[i]);
      i++;
    }

    printf("PASSED !");
    return (0);
  }

}
