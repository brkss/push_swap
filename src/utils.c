/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:43:50 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/13 20:02:20 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	offset(t_stack *a)
{
	if (a->stack_size <= 10)
		return (a->stack_size / 2);
	else if (a->stack_size <= 150)
		return (a->stack_size / 8);
	else
		return (a->stack_size / 18);
}

void	init_data(t_stack *a)
{
	a->metadata.init_size = a->stack_size;
	a->metadata.offset = offset(a);
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
