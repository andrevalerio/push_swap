/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:03:40 by avalerio          #+#    #+#             */
/*   Updated: 2022/05/15 20:36:00 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stk)
{
	int	stk_length;

	stk_length = 0;
	while (stk)
	{
		stk_length++;
		stk = stk->next;
	}
	return (stk_length);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*last;
	int		i;

	i = 0;
	while (i < argc)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			return (NULL);
		
	}}

int	ft_min(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	temp = stack;
	min = stack->num;
	while (temp)
	{
		if (temp->num <= min)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}

void	del_head(t_stack **stack)
{

}
