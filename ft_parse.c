/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:26:17 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:26:21 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Fill the array with values from the map.
*/

void		ft_filler(int x, int y, t_fdf *fdf)
{
	int		file_descr;
	char	*str;
	char	*temp;
	char	**splitt;

	if ((file_descr = open(fdf->name, O_RDONLY)) < 0)
		ft_error("Cannot open file given as an argument.");
	while (get_next_line(file_descr, &str))
	{
		temp = ft_strtrim(str);
		splitt = ft_strsplit(temp, ' ');
		str ? ft_memdel((void *)&str) : 0;
		temp ? ft_memdel((void *)&temp) : 0;
		x = -1;
		while (++x < fdf->x_map && splitt[x])
		{
			fdf->map[y][x].h_1 = ft_atoi(splitt[x]);
			fdf->map[y][x].h_1 > fdf->max_map ? fdf->max_map = \
				fdf->map[y][x].h_1 : 0;
		}
		splitt ? ft_sstrdel(splitt) : 0;
		y++;
	}
	close(file_descr);
	ft_printf(GRN"OK\n\t\tRendering..."RC);
}

/*
** Allocate the array with the map size retrieved below.
*/

void		ft_alloc(int i, t_fdf *fdf)
{
	((fdf->x_map * fdf->y_map) > 1000000) ? \
		ft_error("A non ascii char has been found.") : 0;
	if (!(fdf->map = (t_pxl **)malloc(sizeof(t_pxl *) * fdf->y_map)))
		ft_error("Malloc error.");
	while (i < fdf->y_map)
		if (!(fdf->map[i++] = (t_pxl *)malloc(sizeof(t_pxl) * fdf->x_map)))
			ft_error("Malloc error.");
	ft_filler(0, 0, fdf);
}
