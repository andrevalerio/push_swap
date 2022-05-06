/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:01:48 by avalerio          #+#    #+#             */
/*   Updated: 2022/03/29 03:19:03 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	long long int	minus;
	long long int	number;

	number = 0;
	minus = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-')
	{
		minus = minus * -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	else if (*nptr < '0' || *nptr > '9')
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = (number * 10) + (*nptr - 48);
		nptr++;
	}
	return (number * minus);
}
