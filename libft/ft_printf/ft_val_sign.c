/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:57:52 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/09 15:23:54 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints unsignes integer to standart output.
*/

void	ft_putunsignbr(uintmax_t number)
{
	char	c;

	if (number < 10)
	{
		c = number + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putunsignbr(number / 10);
		ft_putunsignbr(number % 10);
	}
}

/*
** Gets the numbers of digits of the fivem number. If diven number is zero ->
** returns 1. If it is positive number -> it returns how many digits number has.
** If it is negative -> returns the number of digits and '-'.
*/

int		how_many_digs(intmax_t number)
{
	int i;

	if (!number)
		return (1);
	i = number < 0 ? 1 : 0;
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}

/*
** Prints the sign of number ('-' or '+').
** If it is negative it will always print '-'.
** Else, and only if there is a flag with space or plus,
** the space or the plus will be printed.
*/

void	sign_printing_func(intmax_t number, int intel)
{
	char	mark;

	mark = 0;
	if (number < 0)
		mark = '-';
	else if (number >= 0)
	{
		if (intel & PLUS)
			mark = '+';
		else if (intel & SPACE)
			mark = ' ';
	}
	if (mark)
		ft_putchar(mark);
}

/*
** Formating a signed number, getting the number of digits,
** the number of 0 and ' ', and the precision given
** from the format value.
** GOOD LUCK TO UNDERSTAND THIS SHIT (•̀ᴗ•́)و :)
** USAGE FOR THIS:
**	else if (intel->flags & HH)
**		len = ft_signed((char)va_arg(ap, int), intel);
**	else if (intel->flags & H)
**		len = ft_signed((short)va_arg(ap, int), intel);
*/

int		ft_signed(intmax_t number, t_intel *intel)
{
	int i;
	int mark;
	int zero;
	int space;

	i = 0;
	mark = (number >= 0 && (intel->flags & PLUS || \
		intel->flags & SPACE)) ? 1 : 0;
	if (!(intel->flags & PREC) || intel->precision || number)
		i = how_many_digs(number);
	i = i + mark;
	zero = zerosfornbr(intel, (number < 0 || mark), &i);
	space = spacesfornbr(&i, intel->flags, intel->width);
	!(intel->flags & MINUS) ? ft_putnchar(' ', space) : 0;
	sign_printing_func(number, intel->flags);
	ft_putnchar('0', zero);
	if (!(intel->flags & PREC && !intel->precision && !number))
		ft_putunsignbr((number < 0) ? (-number) : (number));
	(intel->flags & MINUS) ? ft_putnchar(' ', space) : 0;
	return (i);
}
