/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:24:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/08 14:15:50 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Finds the length of the wide character.
*/

int		ft_wchrlen(wchar_t c)
{
	int len;

	len = 0;
	if ((int)c < 0x80)
		len++;
	else if ((int)c < 0x800)
		len = len + 2;
	else if ((int)c < 0x10000)
		len = len + 3;
	else
		len = len + 4;
	return (len);
}

/*
** Finds the length of the wide string.
*/

int		ft_wstrlen(wchar_t *wc)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (wc[i] != '\0')
	{
		len = len + ft_wchrlen(wc[i]);
		i++;
	}
	return (len);
}

/*
** The encoding is variable-length and uses 8-bit code units.
*/

int		wchrutf8(char *res, wchar_t c)
{
	int i;

	i = 0;
	if (c <= 0xFF)
		res[i++] = c;
	else if (c < 0x0800)
	{
		res[i++] = ((c >> 6) & 0x1F) | 0xC0;
		res[i++] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (c < 0x010000)
	{
		res[i++] = ((c >> 12) & 0x0F) | 0xE0;
		res[i++] = ((c >> 6) & 0x3F) | 0x80;
		res[i++] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (c < 0x110000)
	{
		res[i++] = ((c >> 18) & 0x07) | 0xF0;
		res[i++] = ((c >> 12) & 0x3F) | 0x80;
		res[i++] = ((c >> 6) & 0x3F) | 0x80;
		res[i++] = ((c >> 0) & 0x3F) | 0x80;
	}
	return (i);
}

/*
** Writes the wide char to the standard output.
*/

int		ft_putwchr(wchar_t c)
{
	int		i;
	char	conv[4];

	i = wchrutf8(conv, c);
	write(1, conv, i);
	return (i);
}

/*
** Prints wide char.
*/

int		ft_wchr(t_intel *intel, va_list arg)
{
	int		i;
	wchar_t	wc;

	wc = va_arg(arg, wint_t);
	i = ft_wchrlen(wc);
	if (!(intel->flags & MINUS))
		i = ft_print_space(intel->width, i, intel->flags);
	ft_putwchr(wc);
	if (intel->flags & MINUS)
		i = ft_print_space(intel->width, i, intel->flags);
	return (i);
}
