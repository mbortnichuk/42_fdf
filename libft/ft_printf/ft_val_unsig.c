/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_unsig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:57:41 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/11 17:24:38 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Used for octal, hexadeciaml and pointer.
** Returns 1 for octal and 2 for hex and pointer.
*/

int		ft_notnbr(int intel, int p, uintmax_t n)
{
	if ((intel & LOWO_B || intel & UPPO_B) && intel & SHARP && \
		(n || (!n && intel & PREC && !p)))
		return (1);
	else if (((intel & LOWX_B || intel & UPPX_B) && intel & SHARP && n) || \
		intel & POINTER_B)
		return (2);
	return (0);
}

/*
** Gets number of 0 from the flags and percision values.
*/

int		zerosfornbr(t_intel *intel, int mark, int *i)
{
	int		zeros;

	zeros = 0;
	if (intel->flags & PREC && intel->precision > *i - mark)
	{
		zeros += intel->precision - *i + mark;
		*i += zeros;
	}
	if (intel->flags & WIDTH && intel->flags & ZERO && !(intel->flags & MINUS)
			&& !(intel->flags & PREC) && intel->width > *i)
	{
		zeros += intel->width - *i;
		*i += zeros;
	}
	return (zeros);
}

/*
** Gets the number of ' ' from the flags and precision values.
*/

int		spacesfornbr(int *i, int intel, int widthminimal)
{
	int		spaces;

	spaces = 0;
	if (intel & WIDTH && (!(intel & ZERO) || intel & MINUS || intel & PREC) && \
		widthminimal > *i)
	{
		spaces += widthminimal - *i;
		*i += spaces;
	}
	return (spaces);
}

/*
** Function that converts an integer value to a '\0' terminated
** string using needed base and number of decimals,
** and returns string with the result value.
*/

char	*unsigned_nbr(uintmax_t n, int *nbr, int base)
{
	int			i;
	char		*converted;
	uintmax_t	save;

	i = 0;
	save = n;
	*nbr = (!n) ? 1 : 0;
	while (save)
	{
		save /= base;
		*nbr += 1;
	}
	converted = ft_memalloc(*nbr);
	CHECK(converted);
	*converted = '0';
	i = (!n) ? 1 : 0;
	while (n)
	{
		save = n % base;
		n /= base;
		converted[i++] = save + '0';
	}
	converted[i] = '\0';
	converted = ft_strrev(converted);
	return (converted);
}

/*
** Formatting an unsigned number, getting the number of digits,
** the number of 0 and ' ', also precision that should be given from the
** format value.
** GOOD LUCK TO UNDERSTAND THIS SHIT (•̀ᴗ•́)و :)
** USAGE FOR THIS:
**  if (intel->flags & L)
**		len = format_unsigned(va_arg(ap, unsigned long), intel, &conv_hex);
**	else if (intel->flags & H)
**		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), \
**			intel, &conv_hex);
*/

int		ft_unsigned(uintmax_t n, t_intel *intel, \
				char *(*modif)(uintmax_t, int*))
{
	int		i;
	int		mark;
	int		zero;
	int		space;
	char	*convertion;

	convertion = modif(n, &i);
	mark = ft_notnbr(intel->flags, intel->precision, n);
	if (intel->flags & LOWX_B || intel->flags & POINTER_B)
		ft_tolowstr(convertion);
	(intel->flags & PREC && !intel->precision && !n) ? i = 0 : i;
	i = i + mark;
	zero = zerosfornbr(intel, (mark == 2) ? 2 : 0, &i);
	space = spacesfornbr(&i, intel->flags, intel->width);
	!(intel->flags & MINUS) ? ft_putnchar(' ', space) : 0;
	ft_notnbr(intel->flags, intel->precision, n) ? ft_putchar('0') : 0;
	if (ft_notnbr(intel->flags, intel->precision, n) > 1)
		intel->flags & UPPX_B ? ft_putchar('X') : ft_putchar('x');
	ft_putnchar('0', zero);
	if (!(intel->flags & PREC && !intel->precision && !n))
		ft_putstr(convertion);
	free(convertion);
	(intel->flags & MINUS) ? ft_putnchar(' ', space) : 0;
	return (i);
}
