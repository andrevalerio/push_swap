/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:09:25 by avalerio          #+#    #+#             */
/*   Updated: 2022/05/02 00:45:07 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

#include <stdio.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}			t_stack;

void	free_stack(t_stack **stack);
void	check_args(int argc, char **argv);
void	check_input(char **argv, int i);
int		stacksize(t_stack *lst);
t_stack	*fill_stack(int argc, char **argv);
int		ft_min(t_stack *stack);
void	del_head(t_stack **stack);
void	move_rr(t_stack **head_ref);
void	move_r(t_stack **head_ref);
void	move_s(t_stack *stack, int c);
void	move_p(t_stack **stack_from, t_stack **stack_to);
void	short_sort(t_stack **s);
void	search_min(t_stack *stack_a, t_stack *stack_b);
void	sort_chunck(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b, int size);

#endif