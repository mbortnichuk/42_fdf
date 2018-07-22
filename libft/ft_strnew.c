/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:54:22 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/04 14:07:39 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *string;

	if (!(string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(string, '\0', size + 1);
	return (string);
}
