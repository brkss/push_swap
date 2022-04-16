/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:43:31 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/16 19:57:09 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_two(t_stack *dest)
{
	if (dest->stack_size == 1)
		exit(0);
	if (dest->stack[0] > dest->stack[1])
	{
		rotate(dest, "ra\n");
		exit(0);
	}
	else
		exit(0);
}

void	handle_three(t_stack *dest)
{
	while (!(dest->stack[0] < dest->stack[1]
			&& dest->stack[1] < dest->stack[2]))
	{
		if (dest->stack[0] > dest->stack[1] && dest->stack[1] < dest->stack[2]
			&& dest->stack[0] > dest->stack[2])
			rotate(dest, "ra\n");
		if (dest->stack[0] < dest->stack[1]
			&& dest->stack[1] > dest->stack[2]
			&& dest->stack[0] > dest->stack[2])
			reverse_rotate(dest, "rra\n");
		if (dest->stack[0] > dest->stack[1]
			|| (dest->stack[0] < dest->stack[1]
				&& dest->stack[2] < dest->stack[1]))
			swap(dest, "sa\n");
	}
}

static int	get_min(t_stack *dest)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = dest->stack[0];
	while (i < dest->stack_size)
	{
		if (min > dest->stack[i])
		{
			min_index = i;
			min = dest->stack[i];
		}
		i++;
	}
	return (min_index);
}

static void	filter_mins(int index, t_stack *a)
{
	if (index > a->stack_size / 2)
	{
		while (index < a->stack_size)
		{
			reverse_rotate(a, "rra\n");
			index++;
		}
	}
	else if (index <= a->stack_size / 2 && index)
	{
		while (index > 0)
		{
			rotate(a, "ra\n");
			index--;
		}
	}
}

void	handle_short(t_stack *a, t_stack *b)
{
	int	index;
	int	n;

	n = 0;
	while (a->stack_size > 3)
	{
		index = get_min(a);
		filter_mins(index, a);
		push(a, b, "pb\n");
	}
	handle_three(a);
	index = 0;
	while (b->stack_size)
	{
		push(b, a, "pa\n");
		index ++;
	}
}
