/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:22 by mbortnic          #+#    #+#             */
/*   Updated: 2018/01/15 12:11:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_strjoin(char *str1, char const *str2)
{
	char *new;
	char *pointer;
	char *temp;

	temp = NULL;
	new = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	CHECK(new);
	if (new)
	{
		temp = new;
		if (str1)
		{
			pointer = str1;
			while (*str1)
				*(new++) = *(str1++);
			free(pointer);
			str1 = NULL;
		}
		if (str2)
			while (*str2)
				*(new++) = *(str2++);
		*new = '\0';
	}
	return (temp);
}

int		search_line(char **line, t_gnl *list, char *buffer, int flg)
{
	char *pointer;
	char *fresh;

	pointer = NULL;
	if (!list->str || (!(*list->str) && !(*buffer)))
		return (END);
	if ((pointer = ft_strchr(list->str, '\n')) && flg == 0)
	{
		*pointer = '\0';
		*line = ft_strdup(list->str);
		fresh = ft_strdup(pointer + 1);
		free(list->str);
		list->str = fresh;
		pointer = NULL;
		return (LINE);
	}
	else if (flg == 1)
	{
		*line = ft_strdup(list->str);
		free(list->str);
		list->str = NULL;
		return (LINE);
	}
	return (END);
}

int		next_line(t_gnl *lst, char **line, const int fd, char buffer[])
{
	size_t	i;

	if (search_line(line, lst, buffer, 0))
		return (LINE);
	while ((i = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[i] = '\0';
		if (!lst->str)
			lst->str = ft_strnew(ft_strlen(buffer));
		if (!(lst->str = ft_new_strjoin(lst->str, buffer)))
			return (ERROR);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (search_line(line, lst, buffer, 0))
		return (LINE);
	else if (i < BUFF_SIZE && (!lst->str || ft_strlen(lst->str) == 0))
		return (END);
	else if (search_line(line, lst, buffer, 1))
		return (LINE);
	return (END);
}

t_gnl	*ft_create_new_list(t_gnl *list, const int fd)
{
	t_gnl *temp;

	temp = (t_gnl *)malloc(sizeof(t_gnl));
	CHECK(temp);
	temp->fd = fd;
	temp->str = NULL;
	temp->next = list;
	list = temp;
	return (list);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*temp;
	char			buffer[BUFF_SIZE + 1];

	if (read(fd, buffer, 0) < 0)
		return (ERROR);
	temp = list;
	while (temp)
	{
		if (temp->fd == fd)
			return (next_line(list, line, fd, buffer));
		temp = temp->next;
	}
	if (!temp)
		list = ft_create_new_list(list, fd);
	return (next_line(list, line, fd, buffer));
}
