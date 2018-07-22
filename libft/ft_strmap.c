/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:33:10 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/06 13:41:23 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	string = ft_strnew(ft_strlen(s));
	if (string)
	{
		while (*s)
			string[i++] = f(*s++);
	}
	return (string);
}
