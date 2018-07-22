/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:16:18 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/09 19:19:34 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converting given number to 10 base (decimal).
*/

char	*convert_to_decimal(uintmax_t number, int *nbr_arr)
{
	char	*conv;

	conv = unsigned_nbr(number, nbr_arr, 10);
	return (conv);
}

/*
** Gets value of a signed number and format it respectively.
** This func returns the number of digits of given number (depending
** on which type of length).
*/

int		s_decimal(t_intel *intel, va_list arg)
{
	int i;

	i = 0;
	if (intel->flags & J || intel->flags & Z)
		i = ft_signed(va_arg(arg, intmax_t), intel);
	else if (intel->flags & LL)
		i = ft_signed(va_arg(arg, long long), intel);
	else if (intel->flags & L || intel->flags & UPPD_B)
		i = ft_signed(va_arg(arg, long), intel);
	else if (intel->flags & H)
		i = ft_signed((short)va_arg(arg, int), intel);
	else if (intel->flags & HH)
		i = ft_signed((char)va_arg(arg, int), intel);
	else
		i = ft_signed(va_arg(arg, int), intel);
	return (i);
}

/*
** Gets the value of a unsigned integer and format it respectively
** This func returns the number of digits of given number (depending
** on which type of length).
*/

int		u_decimal(t_intel *intel, va_list arg)
{
	int i;

	i = 0;
	if (intel->flags & Z)
		i = ft_unsigned(va_arg(arg, size_t), intel, &convert_to_decimal);
	else if (intel->flags & J)
		i = ft_unsigned(va_arg(arg, uintmax_t), intel, &convert_to_decimal);
	else if (intel->flags & LL)
		i = ft_unsigned(va_arg(arg, unsigned long long), intel, \
			&convert_to_decimal);
	else if (intel->flags & L || intel->flags & UPPU_B)
		i = ft_unsigned(va_arg(arg, unsigned long), intel, &convert_to_decimal);
	else if (intel->flags & H)
		i = ft_unsigned((unsigned short)va_arg(arg, unsigned int), intel, \
			&convert_to_decimal);
	else if (intel->flags & HH)
		i = ft_unsigned((unsigned char)va_arg(arg, unsigned int), intel, \
			&convert_to_decimal);
	else
		i = ft_unsigned(va_arg(arg, unsigned int), intel, &convert_to_decimal);
	return (i);
}

/*
** This func returns the length of the number to be printed,
** depending in the length gotten with the flags.
*/

int		ft_number(t_intel *intel, va_list arg)
{
	int i;
	int flg;

	i = 0;
	flg = intel->flags;
	if (flg & LOWI_B || flg & LOWD_B || flg & UPPD_B)
		i = s_decimal(intel, arg);
	if (flg & LOWU_B || flg & UPPU_B)
		i = u_decimal(intel, arg);
	return (i);
}
