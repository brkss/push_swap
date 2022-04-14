/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:52:08 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/14 19:41:04 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 1 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../includes/push_swap.h" 

char	*get_next_line(int fd);
char	*get_line(char *s);
char	*get_rest(char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);
void	is_swap(char *inst, t_stack *a, t_stack *b);
void	is_rotate(char *inst, t_stack *a, t_stack *b);
void	is_reverse_rotate(char *inst, t_stack *a, t_stack *b);
void	is_push(char *inst, t_stack *a, t_stack *b);

#endif
