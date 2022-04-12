/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:50:33 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/12 18:56:46 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int get_index(t_stack *dest, int n)
{  
  int i;
  
  i = dest->stack_size - 1;
  while(i >= 0)
  {
    if(dest->stack[i] == n)
      return(i);
    i--;
  }
  return (-1);
}

static void btoa(t_stack *a, t_stack *b, int *i, int j)
{
  
  if(b->stack[0] == a->metadata.sorted[*i])
  {
    push(b, a, "pa\n");
    (*i)--;
  }
  else if(b->stack[0] > a->stack[a->stack_size - 1] && a->metadata.dawn == 0)
  {
    push(b, a, "pa\n");
    rotate(a, "ra\n");
    a->metadata.dawn++;
  }
  else
  {
    if(j <= b->stack_size / 2)
      rotate(b, "rb\n");
    else
      reverse_rotate(b, "rrb\n");
  }

  //printf("\n--------------- B TO A--------------\n");
  print_stacks(a, b);

}

void check(t_stack *a, t_stack *b)
{
  int index;
  int i;

  i = a->metadata.init_size - 1;
  while(b->stack_size || a->metadata.dawn)
  {
    index = get_index(b, a->metadata.sorted[i]);
    printf("index : %d \n", index);
	if(index >= 0)
      btoa(a, b, &i, index);
    else if(a->metadata.dawn > 0 && a->stack_size > 1)
    {
      reverse_rotate(a, "rra\n");
      a->metadata.dawn--;
      //i--;
    }
  }
}

static void compare(t_stack *a, t_stack *b)
{
  if(a->stack[0] >= a->metadata.sorted[a->metadata.start] 
      && a->stack[0] <= a->metadata.sorted[a->metadata.end - 1])
  {
    push(a, b, "pb\n");
    if(b->stack[0] > a->metadata.sorted[a->metadata.middle] && b->stack_size > 1)
      rotate(b, "rb\n");
  }
  else 
    rotate(a, "ra\n");
}

void sort_long(t_stack *a, t_stack *b)
{
  int i;

  while(a->stack_size)
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
  print_stacks(a, b);
  printf("B size : %d \n", b->stack_size);
  /*
  i = 0;
  while(i < a->metadata.init_size)
	{
		printf("%d \n", a->metadata.sorted[i]);
		i++;
	}
  printf("init size : %d \n", a->metadata.init_size);
  printf("biggest value in refrence : %d \n", a->metadata.sorted[a->metadata.init_size - 1]);
  printf("biggest value index in stack b : %d \n", get_index(b, a->metadata.sorted[a->metadata.init_size - 1]));
  */
  check(a, b);
  //reverse_rotate(a, "rra\n");
}
