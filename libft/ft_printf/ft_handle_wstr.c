/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:23:53 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/07 13:23:16 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Allocates with malloc() and returns a “fresh” wide string ending with ’\0’.
** Each character of the string is initialized at ’\0’.
** If the allocation fails the function returns NULL.
** Same logic as ft_strnew();
*/

wchar_t	*ft_wcsnew(size_t len)
{
	wchar_t	*new;

	new = ft_memalloc(sizeof(wchar_t) * len + sizeof(wchar_t));
	return (new);
}

/*
** Copy at most len wide characters from str into new.
** If str is less than len characters long, the remainder of new is filled
** with `\0' characters. Otherwise, new is not terminated.
** Same logic as ft_strncpy();
*/

wchar_t	*ft_wcsncpy(wchar_t *new, wchar_t *str, size_t len)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (n < len)
	{
		n = n + ft_wchrlen(str[i]);
		if (n > len)
			break ;
		new[i] = str[i];
		new[++i] = L'\0';
	}
	return (new);
}

/*
** Copy the wide string str to new (including `\0' character).
** Same logic as ft_strcpy();
*/

wchar_t	*ft_wcscpy(wchar_t *new, wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i] != L'\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = L'\0';
	return (new);
}

/*
** Allocates sufficient memory for a copy of the wide string, does the copy,
** and returns a pointer to it.
** Same logic as ft_strdup();
*/

wchar_t	*ft_wcsdup(wchar_t *str)
{
	int		i;
	wchar_t	*new;

	i = ft_wstrlen(str) + sizeof(wchar_t);
	new = ft_memalloc(sizeof(wchar_t) * i);
	CHECK(new);
	if (new)
		ft_wcscpy(new, str);
	return (new);
}

/*
** Prints wide string.
*/

int		ft_wstr(t_intel *intel, va_list arg)
{
	int		i;
	wchar_t	*str;
	wchar_t	*dupl;

	if (!(str = va_arg(arg, wchar_t*)))
		str = ft_wcsdup(L"(null)");
	if (intel->flags & PREC)
	{
		dupl = ft_wcsnew(intel->precision);
		CHECK(dupl);
		if (str)
			dupl = ft_wcsncpy(dupl, str, intel->precision);
		str = dupl;
	}
	i = ft_wstrlen(str);
	if (!(intel->flags & MINUS))
		i = ft_print_space(intel->width, i, intel->flags);
	ft_putwstr(str);
	if (intel->flags & MINUS)
		i = ft_print_space(intel->width, i, intel->flags);
	return (i);
}
