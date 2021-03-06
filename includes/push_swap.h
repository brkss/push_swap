/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:56:28 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/16 01:02:08 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_metadata {
	int	*sorted;
	int	offset;
	int	middle;
	int	start;
	int	end;
	int	init_size;
	int	dawn;
}	t_metadata;

typedef struct s_stack {
	int			*stack;
	int			stack_size;
	t_metadata	metadata;
}	t_stack;

int		check_parameters(int count, char **args);
int		ft_atoi(const char *str);
void	fill_stack(t_stack *a, int count, char **args);
void	exit_with_error(void);
int		*sort(t_stack *a);
void	is_sorted(t_stack *a);
void	get_case(t_stack *a, t_stack *b);

// print
void	print_stacks(t_stack *a, t_stack *b);
void	plot_metadata(t_stack *a);

// actions 
void	swap(t_stack *stack, char *ind);
void	push(t_stack *src, t_stack *dest, char *ind);
void	reverse_rotate(t_stack *dest, char *ind);
void	rotate(t_stack *dest, char *ind);

// sort 
void	handle_three(t_stack *dest);
void	handle_two(t_stack *dest);
void	handle_short(t_stack *a, t_stack *b);
void	sort_long(t_stack *a, t_stack *b);

// long sort 
void	init_data(t_stack *a);

void	shift_down(t_stack *stack);
void	shift_up(t_stack *stack);

// utils
void	put_str(char *str);
#endif
