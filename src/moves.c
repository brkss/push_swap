/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:43:06 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/13 17:43:09 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack *stack, char *ind)
{
  int tmp;

  tmp = stack->stack[0];
  stack->stack[0] = stack->stack[1];
  stack->stack[1] = tmp;
  put_str(ind);
}

static void shift_down(t_stack *stack)
{
  int i;

  i = stack->stack_size - 1;
  while(i > 0)
  {
    stack->stack[i] = stack->stack[i - 1];
    i--;
  }
  stack->stack[0] = 0;
}

static void shift_up(t_stack *stack)
{
  int i;

  i = 0;
  while(i < stack->stack_size -1)
  {
    stack->stack[i] = stack->stack[i + 1];
    i++;
  }
  stack->stack[i] = 0; 
}

// push from stack src to stack dest ;;;
void push(t_stack *src, t_stack *dest, char *ind)
{
  dest->stack_size++;
  shift_down(dest);
  dest->stack[0] = src->stack[0];
  shift_up(src);
  src->stack_size--;
  put_str(ind);
}

void rotate(t_stack *dest, char *ind)
{
  int i;
  int tmp;

  tmp = dest->stack[0];
  i = 1;
  while(i < dest->stack_size)
  {
    dest->stack[i - 1] = dest->stack[i];
    i++;
  }
  dest->stack[dest->stack_size - 1] = tmp;
  put_str(ind);
}

void reverse_rotate(t_stack *dest, char *ind)
{
  int i;
  int tmp;

  i = dest->stack_size - 1;
  if(i < 0)
    return;
  tmp = dest->stack[i];
  while(i > 0)
  {
    dest->stack[i] = dest->stack[i - 1];
    i--;
  }
  dest->stack[0] = tmp;
  put_str(ind);
} 

