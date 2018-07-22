/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:16:41 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/16 16:16:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_node(void *content)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(*list));
	list->content = content;
	list->next = NULL;
	return (list);
}
