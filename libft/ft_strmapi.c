/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:16:36 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/06 13:41:34 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	string = ft_strnew(ft_strlen(s));
	if (string)
	{
		while (s[i])
		{
			string[i] = f(i, s[i]);
			i++;
		}
	}
	return (string);
}
