/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:32:36 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/27 18:32:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t size)
{
	size_t	i;
	char	*new;

	i = -1;
	new = (char *)malloc(sizeof(char) * (size + 1));
	CHECK(new);
	while (++i < size)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}
