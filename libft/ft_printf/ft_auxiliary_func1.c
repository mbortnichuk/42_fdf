/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary_func1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 13:03:00 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/12 16:13:58 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints at most len wide string to the standart output.
*/

int		ft_putwnstr(wchar_t *ws, size_t len)
{
	size_t	i;
	int		ll;

	ll = 0;
	i = 0;
	while (*ws && i < len)
	{
		ft_putwchr(*ws++);
		ll = ll + ft_wstrlen(ws);
		i++;
	}
	return (ll);
}

/*
** Writes the wide string to the standard output.
** Same logic as ft_putstr();
*/

int		ft_putwstr(wchar_t *wstr)
{
	int		i;

	i = 0;
	while (*wstr)
	{
		ft_putwchr(*wstr++);
		i = i + ft_wchrlen(*wstr);
	}
	return (i);
}

/*
** Makes every letter in the string lowercase.
*/

char	*ft_tolowstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
