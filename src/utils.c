/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:43:50 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/16 01:05:23 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shift_down(t_stack *stack)
{
	int	i;

	i = stack->stack_size - 1;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = 0;
}

void	shift_up(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->stack_size -1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = 0;
}

static int	offset(t_stack *a)
{
	if (a->stack_size <= 10)
		a->metadata.offset = a->stack_size / 2;
	else if (a->stack_size <= 150)
		a->metadata.offset = a->stack_size / 8;
	else if (a->stack_size > 150)
		a->metadata.offset = a->stack_size / 18;
	return (1);
}

void	init_data(t_stack *a)
{
	a->metadata.init_size = a->stack_size;
	offset(a);
	a->metadata.middle = a->stack_size / 2;
	a->metadata.start = a->metadata.middle - a->metadata.offset;
	a->metadata.end = a->metadata.middle + a->metadata.offset;
}

void	put_str(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
