/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:56:14 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/09 16:59:11 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints number of spaces.
*/

int		ft_print_space(int w, int i, int intel)
{
	while ((w - i) > 0)
	{
		ft_putchar(((intel & ZERO) && !(intel & MINUS)) ? '0' : ' ');
		i++;
	}
	return (i);
}

/*
** If no specifier is found, prints the character, plus the specific
** justification given the minus flag: (left or right).
*/

int		ft_print_nothing(t_intel *intel, char c)
{
	int		i;

	if (!(intel->flags & MINUS))
		i = ft_print_space(intel->width, sizeof(char), intel->flags);
	write(1, &c, 1);
	if (intel->flags & MINUS)
		i = ft_print_space(intel->width, sizeof(char), intel->flags);
	return (i);
}

/*
** Prints the specific specifier given from the format.
*/

int		print_all(t_intel *intel, va_list ap, char frm, int i)
{
	int		output;

	output = 0;
	if (i == STRING)
		output = ft_str(intel, ap);
	else if (i == WSTRING)
		output = ft_wstr(intel, ap);
	else if (i == LOWC)
		output = ft_chr(intel, ap);
	else if (i == UPPC)
		output = ft_wchr(intel, ap);
	else if (i == LOWX || i == UPPX || i == POINTER)
		output = ft_hex(intel, ap);
	else if (i == LOWO || i == UPPO)
		output = ft_oct(intel, ap);
	else if ((i == LOWD || i == UPPD || i == LOWI) || \
		(i == LOWU || i == UPPU))
		output = ft_number(intel, ap);
	else
		output = ft_print_nothing(intel, frm);
	return (output);
}

/*
** If successful, the total number of characters written is returned.
** On failure, a negative number is returned.
*/

int		to_output(const char *frm[], va_list ap)
{
	int		specifier;
	t_intel	intel;

	intel.width = 0;
	intel.precision = 0;
	intel.flags = 0;
	specifier = parsespec(&intel, ap, (char**)frm);
	if (!**frm)
		return (-1);
	return (print_all(&intel, ap, (char)**frm, specifier));
}
