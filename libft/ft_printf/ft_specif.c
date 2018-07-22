/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:26:23 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/04 12:20:26 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets every specifier position from the format.
*/

int		specpos(char *specifier, char c)
{
	int		position;

	position = 0;
	while (specifier[position])
	{
		if (c == specifier[position])
			return (position);
		position++;
	}
	return (-1);
}

/*
** Gets which specifier is in the format, and encode it given its respective bit
** value (going from bit 0, to bit 13 for the mandatory specifiers).
*/

int		findspec(t_intel *intel, char *specifier, char c)
{
	int		*array;
	int		spec;

	array = (int *)malloc(sizeof(int) * SPECSCOUNT);
	array[STRING] = STRING_B;
	array[WSTRING] = WSTRING_B;
	array[POINTER] = POINTER_B;
	array[LOWD] = LOWD_B;
	array[UPPD] = UPPD_B;
	array[LOWI] = LOWI_B;
	array[LOWO] = LOWO_B;
	array[UPPO] = UPPO_B;
	array[LOWU] = LOWU_B;
	array[UPPU] = UPPU_B;
	array[LOWX] = LOWX_B;
	array[UPPX] = UPPX_B;
	array[LOWC] = LOWC_B;
	array[UPPC] = UPPC_B;
	if (((spec = specpos(specifier, c)) != -1) && c)
		intel->flags |= array[spec];
	free(array);
	return (spec);
}

/*
** Parse the specifier, returning the specifier positing.
** If the attribute isn't valid, returns a printf error.
*/

int		parsespec(t_intel *intel, va_list ap, char **frm)
{
	int		spec;
	int		ok;
	char	*converse;

	intel->flags = 0;
	converse = ft_memalloc(SPECSCOUNT);
	CHECK(converse);
	spec = -1;
	converse = ft_strncpy(converse, SPECS, SPECSCOUNT);
	while (**frm)
	{
		if ((specpos(converse, **frm) != -1) && \
			(spec = findspec(intel, converse, **frm)))
			break ;
		if (!(ok = get_all_fl(intel, ap, frm)))
			break ;
	}
	free(converse);
	return (spec);
}
