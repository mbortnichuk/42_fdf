/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:02:45 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/08 17:45:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints string.
*/

int		ft_str(t_intel *intel, va_list arg)
{
	int		i;
	char	*dupl;
	char	*str;

	if (intel->flags & L)
		return (ft_wstr(intel, arg));
	if (!(str = va_arg(arg, char*)))
		str = ft_strdup("(null)");
	if (intel->flags & PREC)
	{
		dupl = ft_strnew(intel->precision);
		CHECK(dupl);
		dupl = ft_strncpy(dupl, str, intel->precision);
		str = dupl;
	}
	i = ft_strlen(str);
	if (!(intel->flags & MINUS))
		i = ft_print_space(intel->width, i, intel->flags);
	ft_putstr(str);
	if (intel->flags & MINUS)
		i = ft_print_space(intel->width, i, intel->flags);
	return (i);
}

/*
** Prints char.
*/

int		ft_chr(t_intel *intel, va_list ap)
{
	int		i;
	char	c;

	if (intel->flags & L)
		return (ft_wchr(intel, ap));
	i = sizeof(char);
	c = va_arg(ap, int);
	if (!(intel->flags & MINUS))
		i = ft_print_space(intel->width, i, intel->flags);
	write(1, &c, 1);
	if (intel->flags & MINUS)
		i = ft_print_space(intel->width, i, intel->flags);
	return (i);
}
