/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:42:23 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/10 15:13:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*number;
	unsigned int	nb;
	int				length;

	length = ft_numberlength(n);
	number = (ft_strnew(length));
	if (!number)
		return (0);
	nb = n;
	if (n < 0)
	{
		number[0] = '-';
		nb = -n;
	}
	if (n == 0)
		number[0] = '0';
	number[length--] = '\0';
	while (nb != 0)
	{
		number[length--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (number);
}
