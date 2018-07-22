/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:20:35 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/18 13:30:23 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *beginning)
{
	t_list	*list;
	int		i;

	i = 0;
	list = beginning;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
