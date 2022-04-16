/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:25:37 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/16 01:10:56 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "checker.h"

void	handle_instruction(char *inst, t_stack *a, t_stack *b)
{
	is_swap(inst, a, b);
	is_rotate(inst, a, b);
	is_reverse_rotate(inst, a, b);
	is_push(inst, a, b);
}

int	sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->stack_size && a->stack[i] == a->metadata.sorted[i])
		i++;
	if (i == a->stack_size)
		return (1);
	return (0);
}

void	follow_instructions(t_stack *a, t_stack *b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		handle_instruction(instruction, a, b);
		free(instruction);
		instruction = get_next_line(0);
	}
}

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
		follow_instructions(a, b);
		if (sorted(a))
			put_str("OK\n");
		else
			put_str("KO\n");
	}
	return (0);
}
