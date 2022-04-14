/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:25:37 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/14 18:50:47 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
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

void	handle_instruction(char *inst, t_stack *a, t_stack *b)
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
	else if (!ft_strcmp(inst, "ra\n"))
		rotate(a, NULL);
	else if (!ft_strcmp(inst, "rb\n"))
		rotate(b, NULL);
	else if (!ft_strcmp(inst, "rr\n"))
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (!ft_strcmp(inst, "rra\n"))
		reverse_rotate(a, NULL);
	else if (!ft_strcmp(inst, "rrb\n"))
		reverse_rotate(b, NULL);
	else if (!ft_strcmp(inst, "rrr\n"))
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, NULL);
	}
	else if (!ft_strcmp(inst, "pa\n"))
		push(b, a, NULL);
	else if (!strcmp(inst, "pb\n"))
		push(a, b, NULL);
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

int	main(int argc, char **argv)
{
	char	*instruction;
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		if (!check_parameters(argc, argv))
			exit(0);
		a = (t_stack *)malloc(sizeof(t_stack));
		b = (t_stack *)malloc(sizeof(t_stack));
		a->stack = (int *)malloc(sizeof(int) * argc - 1);
		b->stack = (int *)malloc(sizeof(int) * argc - 1);
		a->stack_size = argc - 1;
		b->stack_size = 0;
		fill_stack(a, argc, argv);
		a->metadata.sorted = sort(a);
		instruction = get_next_line(0);
		while (instruction)
		{
			handle_instruction(instruction, a, b);
			free(instruction);
			instruction = get_next_line(0);
		}
		print_stacks(a, b);
		if (sorted(a))
			put_str("OK\n");
		else
			put_str("KO\n");
	}
	return (0);
}
