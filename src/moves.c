/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:57:25 by avalerio          #+#    #+#             */
/*   Updated: 2022/05/02 00:30:18 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rr(t_stack **head_ref)
{
	t_stack		*seclast;
	t_stack		*last;

	last = *head_ref;
	seclast = NULL;
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = *head_ref;
	*head_ref = last;
	write(1, "rra\n", 4);
}

void	move_r(t_stack **head_ref)
{
	t_stack		*first;
	t_stack		*last;

	first = *head_ref;
	last = *head_ref;
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	*head_ref = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	move_s(t_stack *stack, int c)
{
	int	temp;

	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}

void	move_p(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->num = (*stack_from)->num;
	new->next = *stack_to;
	*stack_to = new;
	del_head(stack_from);
}
