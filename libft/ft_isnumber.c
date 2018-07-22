/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:18:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/20 14:23:49 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int		i;
	int		test;

	i = 0;
	test = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			test++;
		i++;
	}
	if ((int)ft_strlen(str) == test)
		return (1);
	else
		return (0);
}
