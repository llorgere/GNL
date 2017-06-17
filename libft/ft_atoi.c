/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:28:39 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 15:25:12 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		nb;

	neg = 0;
	nb = 0;
	while (*str == '\n' || *str == '\f' || *str == '\t'
			|| *str == '\v' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg = 1;
	}
	while (*str <= '9' && *str >= '0')
	{
		nb = nb * 10;
		nb = nb + *str - '0';
		str++;
	}
	if (neg == 1)
		nb = nb * (-1);
	return (nb);
}
