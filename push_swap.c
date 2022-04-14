/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:28:08 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/14 19:38:13 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		if (!check_parameters(argc, argv))
		{
			put_str("Error\n");
			exit(0);
		}
		a = (t_stack *)malloc(sizeof(t_stack));
		b = (t_stack *)malloc(sizeof(t_stack));
		a->stack = (int *)malloc(sizeof(int) * argc - 1);
		b->stack = (int *)malloc(sizeof(int) * argc - 1);
		a->stack_size = argc - 1;
		b->stack_size = 0;
		fill_stack(a, argc, argv);
		a->metadata.sorted = sort(a);
		is_sorted(a);
		get_case(a, b);
		return (0);
	}
}
