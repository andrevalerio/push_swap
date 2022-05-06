/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:10:58 by avalerio          #+#    #+#             */
/*   Updated: 2022/05/02 00:45:12 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack **s)
{
	int	a;
	int	b;
	int	c;

	a = (*s)->num;
	b = (*s)->next->num;
	c = (*s)->next->next->num;
	if (a > b && b < c && a < c)
		move_s((*s), 'a');
	else if (a < b && b > c && a < c)
	{
		move_rr(s);
		move_s((*s), 'a');
	}
	else if (a > b && a > c && b < c)
		move_r(s);
	else if (a < b && a > c && b > c)
		move_rr(s);
	else if (a > b && b > c && c < a)
	{
		move_r(s);
		move_s((*s), 'a');
	}
	else
		return ;
}

void	search_min(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = ft_min(stack_a);
	while(stack_a->num != min)
	{
		if(stack_a->next->num != min)
			move_rr(&stack_a);
		else
			move_r(&stack_a);
	}
	move_p(&stack_a, &stack_b);
}

void	sort_chunck(t_stack *stack_a, t_stack *stack_b)
{
	while (stacksize(stack_a) > 3)
		search_min(stack_a, stack_b);
	short_sort(&stack_a);
	while(stacksize(stack_b))
		move_p(&stack_b, &stack_a);
}

void	sort(t_stack **stack_a,t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->num < (*stack_a)->next->num)
			return ;
		else
			move_s(*stack_a, 'a');
	}
	else if (size == 3)
		short_sort(stack_a);
	else if (size <= 19)
		sort_chunck(*stack_a, *stack_b);
}
