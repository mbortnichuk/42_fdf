/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:05:41 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/13 19:07:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	blanks(int n)
{
	if (n == ' ' || n == '\t' || n == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*ret;

	if (!s)
		return (NULL);
	i = 0;
	while (blanks(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && blanks(s[len]))
		len--;
	if (len < i)
		return (ret = ft_strdup("\0"));
	return (ret = ft_strsub(s, i, len - (size_t)i + 1));
}
