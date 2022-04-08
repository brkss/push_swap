
#include "../includes/push_swap.h"

static void fill(int *src, int src_size, int *dest)
{
  int i;

  if(!src || src_size == 0)
    return;
  i = 0;
  while(i < src_size)
  {
    dest[i] = src[i];
    i++;
  }
}

void is_sorted(t_stack *a)
{
  int i;

  i = 0;
  while(i < a->stack_size && a->stack[i] == a->metadata.sorted[i])
    i++;
  if(i == a->stack_size)
    exit(0);
}

int *sort(t_stack *a)
{

  int tmp;
  int min;
  int i;
  int *arr;

  i = 0;
  min = 0;
  arr = (int *)malloc(sizeof(int) * a->stack_size);
  fill(a->stack, a->stack_size, arr);
  while(min < a->stack_size)
  {
    i = min;
    while(i < a->stack_size){
      if(arr[min] > arr[i]){
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
      }
      i++;
    }
    min++;
  }
  return (arr);
}
