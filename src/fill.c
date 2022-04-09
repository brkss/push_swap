

#include "../includes/push_swap.h"


static int check_dup(int *arr, int size, int n){
    int i;

    i = 0;
    while(i < size){
      if(arr[i] == n)
        return (0);
      i++;
    }
    return (1);
} 

void fill_stack(t_stack *a, int count, char **args)
{

  int i;
  int n;

  if(!a || !args || count == 0)
    return;
  i = 0;
  while(i < count - 1){
    n = ft_atoi(args[i + 1]);
    if(!check_dup(a->stack, i, n))
      exit_with_error();
    a->stack[i] = n;
    i++;
  }
  return;
}
