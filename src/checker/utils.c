/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:58:24 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/14 19:41:20 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../../includes/push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	is_swap(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(inst, "sa\n"))
		swap(a, NULL);
	else if (!ft_strcmp(inst, "sb\n"))
		swap(b, NULL);
	else if (!ft_strcmp(inst, "ss\n"))
	{
		swap(a, NULL);
		swap(b, NULL);
	}
}

void	is_rotate(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(inst, "ra\n"))
		rotate(a, NULL);
	else if (!ft_strcmp(inst, "rb\n"))
		rotate(b, NULL);
	else if (!ft_strcmp(inst, "rr\n"))
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
}

void	is_reverse_rotate(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(inst, "rra\n"))
		reverse_rotate(a, NULL);
	else if (!ft_strcmp(inst, "rrb\n"))
		reverse_rotate(b, NULL);
	else if (!ft_strcmp(inst, "rrr\n"))
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, NULL);
	}
}

void	is_push(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(inst, "pa\n"))
		push(b, a, NULL);
	else if (!strcmp(inst, "pb\n"))
		push(a, b, NULL);
}
