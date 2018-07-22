/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:14:37 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/10 15:44:22 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		skip_blanks(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || \
			c == '\f' || c == '\r' || c == '\n');
}

int				ft_atoi(const char *str)
{
	int					i;
	unsigned long int	res;
	int					neg;

	i = 0;
	res = 0;
	neg = 1;
	while (skip_blanks(str[i]))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		if ((res > 922337203685477580 || (res == 922337203685477580 && \
			(str[i] - '0') > 7)) && neg == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580 && \
			(str[i] - '0') > 8)) && neg == -1)
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}
