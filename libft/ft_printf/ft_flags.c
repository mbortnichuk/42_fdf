/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:26:16 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/09 19:29:35 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Modifies the length of the data type.
** The following chart shows the types used to interpret the corresponding
** specifier with and without the length specifier.
**
** length  | d i           | u o O x X b            | c      | s        | p
** -----------------------------------------------------------------------------
** (none)  | int           | unsigned int           | int    | char*    | void*
** hh      | signed char   | unsigned char          |        |          |
** h       | short int     | unsigned short int     |        |          |
** l       | long int      | unsigned long int      | wint_t | wchar_t* |
** ll      | long long int | unsigned long long int |        |          |
** j       | intmax_t      | uintmax_t              |        |          |
** z       | size_t        | size_t                 |        |          |
*/

int		length(t_intel *intel, char *frm)
{
	int		l;

	l = 0;
	while (frm[l] == 'h' || frm[l] == 'l' || frm[l] == 'j' || frm[l] == 'z')
	{
		if (frm[l] == 'h')
			frm[l + 1] == 'h' ? (intel->flags |= HH) : (intel->flags |= H);
		if (frm[l] == 'l')
			frm[l + 1] == 'l' ? (intel->flags |= LL) : (intel->flags |= L);
		if (intel->flags == HH || intel->flags == LL)
			l++;
		if (frm[l] == 'j')
			intel->flags |= J;
		if (frm[l] == 'z')
			intel->flags |= Z;
		l++;
	}
	return (l);
}

/*
** Get flags, and store them in the atribute structure.
** If there's no flag, function returns a zero (0), else returns one (1).
**
** @SHARP : Used with o, x or X specifiers the value is preceeded with
**          0, 0x or 0X respectively for values different than zero.
**          By default, if no digits follow, no decimal point is written.
** @ZERO  : Left-pads the number with zeroes (0) instead of spaces
**          when padding is specified
** @MINUS : Left-justify within the given field width;
**          Right justification is the default
** @SPACE : If no sign is going to be written, a blank space is inserted
**          before the value.
** @PLUS  : Forces to preceed the result with a plus or minus sign (+ or -),
**          even for positive numbers. By default, only negative numbers are
**          preceded with a minus (-) sign.
*/

int		flags(t_intel *intel, char c)
{
	if (c == '#')
		return (intel->flags |= SHARP);
	else if (c == '-')
		return (intel->flags |= MINUS);
	else if (c == '+')
		return (intel->flags |= PLUS);
	else if (c == '0')
		return (intel->flags |= ZERO);
	else if (c == ' ')
		return (intel->flags |= SPACE);
	else
		return (0);
	return (c == '#' || c == '-' || c == '+' || c == '0' || c == ' ');
}

/*
** Controls the minimum number of characters that are output. If the number of
** characters in the output value is less than the specified width, blanks are
** added to the left or the right of the values—depending on whether the left
** alignment flag (-) is specified—until the minimum width is reached.
** @star (*) : Not specified in the format string, but as an additional integer
**             value argument preceding the argument that has to be formatted.
** @number   : Minimum number of characters to be printed. If the value to be
**             printed is shorter than this number, the result is padded with
**             blank spaces.
*/

int		width(t_intel *intel, va_list ap, char *frm)
{
	int		w;
	char	*n;

	w = 0;
	if (frm[w] == '*')
	{
		intel->width = va_arg(ap, int);
		if (intel->width < 0)
		{
			intel->width *= -1;
			intel->flags |= MINUS;
		}
		w = 1;
	}
	else
	{
		while (frm[w] >= '0' && frm[w] <= '9')
			w++;
		if (!w || !(n = ft_strsub(frm, 0, w)))
			return (0);
		intel->width = ft_atoi(n);
		ft_strdel(&n);
	}
	return (w);
}

/*
** Specifies the number of string characters, the number of decimal places,
** or the number of significant digits to be output.
** For numbers, precision is the minimum number of digits to be written.
** If the value to be written is shorter than this number, the result is padded
** with leading zeros. The value is not truncated even if the result is longer.
** For strings, is the maximum number of characters to be printed.
** By default all characters are printed until a null character is encountered.
*/

int		precision(t_intel *intel, va_list arg, char *frm)
{
	int		p;
	char	*n;

	p = 0;
	if (frm[0] == '.')
	{
		p = 1;
		if (frm[p] == '*')
		{
			intel->precision = va_arg(arg, int);
			p++;
		}
		else
		{
			while (frm[p] >= '0' && frm[p] <= '9')
				p++;
			if (!(n = ft_strsub(frm, 1, p)))
				return (0);
			intel->precision = (p != 1) ? ft_atoi(n) : 0;
			ft_strdel(&n);
		}
	}
	return (p);
}

/*
** Gets the flags, width, precision and length of the format.
** Returns a boolean value (one (1) or zero (0)), indicating if the format
** is valid.
*/

int		get_all_fl(t_intel *intel, va_list ap, char **frm)
{
	char	*all;
	int		fw;

	all = *frm;
	while (flags(intel, **frm))
		(*frm)++;
	while ((fw = length(intel, *frm)))
		(*frm) += fw;
	while ((fw = precision(intel, ap, *frm)))
	{
		if (intel->precision >= 0)
			intel->flags |= PREC;
		(*frm) += fw;
	}
	while ((fw = width(intel, ap, *frm)))
	{
		intel->flags |= WIDTH;
		(*frm) += fw;
	}
	return (*frm > all);
}
