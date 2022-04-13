/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:42:19 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/13 17:46:38 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_case(t_stack *a, t_stack *b)
{
	if (a->stack_size < 3)
		handle_two(a);
	else if (a->stack_size == 3)
		handle_three(a);
	else if (a->stack_size == 4 || a->stack_size == 5)
		handle_short(a, b);
	else
	{
		init_data(a);
		sort_long(a, b);
	}
}
