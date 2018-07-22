/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:52:36 by mbortnic          #+#    #+#             */
/*   Updated: 2017/11/16 13:32:42 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *llist;

	if (!(llist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		llist->content = NULL;
		llist->content_size = 0;
	}
	else
	{
		if ((llist->content = malloc(content_size)) == NULL)
		{
			free(llist);
			return (NULL);
		}
		ft_memcpy((llist->content), content, content_size);
		llist->content_size = content_size;
	}
	llist->next = NULL;
	return (llist);
}
