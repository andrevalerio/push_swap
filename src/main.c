/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:58:54 by avalerio          #+#    #+#             */
/*   Updated: 2022/05/02 00:41:23 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		check_input(argv, i);
		i++;
	}
}

static void printlist(t_stack *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->num);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc == 1)
		return (0);
	argv = &argv[1];
	argc--;
	check_args(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	size = stacksize(stack_a);
	sort(&stack_a, &stack_b, size);
	/*move_r(&stack_a);
	move_s(stack_a, 'a');*/
	printlist(stack_a);
	printlist(stack_b);
	printf("\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
}
