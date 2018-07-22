/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:38:23 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/07 17:49:49 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;

	if (s != NULL)
	{
		string = (char *)malloc(sizeof(char) * len + 1);
		if (string != NULL)
		{
			i = 0;
			while (i < len)
				string[i++] = s[start++];
			string[i] = '\0';
			return (string);
		}
	}
	return (0);
}
