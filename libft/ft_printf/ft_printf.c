/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:03:57 by mbortnic          #+#    #+#             */
/*   Updated: 2018/01/18 20:07:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Writes the string pointed by format to the standard output (stdout),
** replacing any format specifier in the same way as printf does, but using the
** elements in the variable argument list identified by arg instead of
** additional function arguments.
*/

int		ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((i = to_output(&format, ap)) == -1)
				break ;
			len = len + i;
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
