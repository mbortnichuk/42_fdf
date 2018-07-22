/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:15:25 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/09 19:26:27 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converting given number to 8 base (octal base).
*/

char	*convert_to_oct(uintmax_t n, int *nbr)
{
	char *conv;

	conv = unsigned_nbr(n, nbr, 8);
	return (conv);
}

/*
** This func returns the length of octal number that will be printed to the
** standart output, depending in the length gotten with the flags.
*/

int		ft_oct(t_intel *intel, va_list arg)
{
	int i;

	i = 0;
	if (intel->flags & Z)
		i = ft_unsigned(va_arg(arg, size_t), intel, &convert_to_oct);
	else if (intel->flags & J)
		i = ft_unsigned(va_arg(arg, uintmax_t), intel, &convert_to_oct);
	else if (intel->flags & LL)
		i = ft_unsigned(va_arg(arg, unsigned long), intel, &convert_to_oct);
	else if (intel->flags & L || intel->flags & UPPO_B)
		i = ft_unsigned(va_arg(arg, unsigned long), intel, &convert_to_oct);
	else if (intel->flags & H)
		i = ft_unsigned((unsigned short)va_arg(arg, unsigned int), \
			intel, &convert_to_oct);
	else if (intel->flags & HH)
		i = ft_unsigned((unsigned char)va_arg(arg, unsigned int), \
			intel, &convert_to_oct);
	else
		i = ft_unsigned(va_arg(arg, unsigned int), intel, &convert_to_oct);
	return (i);
}
