/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:20:10 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/16 13:26:07 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *newlist;

	if (!alst || !del || !*alst)
		return ;
	list = *alst;
	while (list)
	{
		newlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = newlist;
	}
	*alst = NULL;
}
