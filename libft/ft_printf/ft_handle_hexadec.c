/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexadec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:12:29 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/09 19:15:33 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the hexadecimal number, firstly assigning every char
** into the hex string,
** then reversing the char's to get the correct value
** (almost same logic as ft_itoa()).
*/

char	*is_hex_n(char *hex, char *hstr, uintmax_t number)
{
	int i;
	int size;

	i = 0;
	size = !number ? 1 : 0;
	while (number)
	{
		hex[size++] = hstr[number & 0xF];
		number >>= 4;
	}
	while (i < (size / 2))
	{
		hex[i] ^= hex[size - i - 1];
		hex[size - i - 1] ^= hex[i];
		hex[i] ^= hex[size - i - 1];
		i++;
	}
	return (hex);
}

/*
** Gets how many digits should the hexadec number have
** (length of hexadecimal value).
*/

int		hex_dig(uintmax_t number)
{
	int i;

	i = !number ? 1 : 0;
	while (number)
	{
		i++;
		number >>= 4;
	}
	return (i);
}

/*
** Converting given number to 16 base (hexadecimal base).
*/

char	*convert_to_hex(uintmax_t number, int *nbr)
{
	char	*nhex;
	char	*shex;
	char	*str;

	str = "0123456789ABCDEF";
	*nbr = hex_dig(number);
	nhex = ft_strnew(*nbr);
	CHECK(nhex);
	*nhex = '0';
	shex = ft_strdup(str);
	CHECK(shex);
	nhex = is_hex_n(nhex, shex, number);
	ft_strdel(&shex);
	return (nhex);
}

/*
** This function returns the length of the hexadecimal number
** that will be printed
** to the standart output, depending in the length
** gotten with the flags.
*/

int		ft_hex(t_intel *intel, va_list arg)
{
	int i;

	i = 0;
	if (intel->flags & Z)
		i = ft_unsigned(va_arg(arg, size_t), intel, &convert_to_hex);
	else if (intel->flags & J)
		i = ft_unsigned(va_arg(arg, uintmax_t), intel, &convert_to_hex);
	else if (intel->flags & LL)
		i = ft_unsigned(va_arg(arg, unsigned long long), intel, \
			&convert_to_hex);
	else if (intel->flags & L)
		i = ft_unsigned(va_arg(arg, unsigned long), intel, &convert_to_hex);
	else if (intel->flags & H)
		i = ft_unsigned((unsigned short)va_arg(arg, unsigned int), intel, \
			&convert_to_hex);
	else if (intel->flags & HH)
		i = ft_unsigned((unsigned char)va_arg(arg, unsigned int), intel, \
			&convert_to_hex);
	else if (intel->flags & POINTER_B)
		i = ft_unsigned((uintmax_t)va_arg(arg, void*), intel, &convert_to_hex);
	else
		i = ft_unsigned(va_arg(arg, unsigned int), intel, &convert_to_hex);
	return (i);
}
