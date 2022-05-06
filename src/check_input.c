/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:59:17 by avalerio          #+#    #+#             */
/*   Updated: 2022/04/02 22:57:57 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static void	check_dupl(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while(argv[i])
	{
		j = 0;
		while(argv[j])
		{
			if (i != j && (ft_strncmp(argv[i], argv[j], sizeof(argv[i])) == 0))
				print_error();
			j++;
		}
		i++;
	}
}

void	check_input(char **argv, int i)
{
	int		j;
	double	num;

	j = 0;
	num = 0;
	if (argv[i][j] == '-')
	{
		j++;
		if (!argv[i][j])
			print_error();
	}
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
			print_error();
		j++;
	}
	num = ft_atoi(argv[i]);
	if (num > INT_MAX || num < INT_MIN)
		print_error();
	check_dupl(argv);	
}
