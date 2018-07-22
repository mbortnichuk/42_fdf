/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary_func2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:14:20 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/12 16:21:51 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints at most len string to the standart output.
*/

void	ft_putnstr(char const *s, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		write(1, &s[i], 1);
}

/*
** Prints to the standart output char specific number of times.
*/

void	ft_putnchar(char c, int t)
{
	while (t-- > 0)
		write(1, &c, 1);
}

/*
** Function to reverse string in-place.
*/

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}
