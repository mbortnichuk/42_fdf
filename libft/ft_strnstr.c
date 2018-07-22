/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:59:19 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/15 13:47:46 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t i;
	size_t j;

	if (lit[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		while (big[i] && lit[j] && big[i] == lit[j] && i < len)
		{
			i++;
			j++;
		}
		if (j == ft_strlen(lit))
			return ((char *)big + i - j);
		else
			i = (i - j) + 1;
		j = 0;
	}
	return (NULL);
}
