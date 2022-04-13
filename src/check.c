/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:42:29 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/13 17:50:23 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_alphanum(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

static int	is_arg_alphanum(char *arg)
{
	if (!arg)
		return (0);
	while (*arg)
	{
		if (!is_alphanum(*arg))
			return (0);
		arg++;
	}
	return (1);
}

int	check_parameters(int count, char **args)
{
	int	i;

	i = 1;
	while (i < count && args[i])
	{
		if (!is_arg_alphanum(args[i]))
			return (0);
		i++;
	}
	return (1);
}
