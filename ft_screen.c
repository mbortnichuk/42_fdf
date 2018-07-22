/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:22:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:22:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Display the multiplier and speed value on screen.
*/

void		ft_data_var(t_fdf *fdf, int offx, int offy)
{
	char	*vtmp;
	char	*temp;

	vtmp = ft_itoa(fdf->height);
	temp = ft_strjoin("Height scale: ", vtmp);
	mlx_string_put(fdf->mlx.mlx, fdf->mlx.win, 5, fdf->y_wind - 25, 0x3399FF, temp);
	temp ? ft_memdel((void *)&temp) : 0;
	vtmp ? ft_memdel((void *)&vtmp) : 0;
	vtmp = ft_itoa(fdf->sp);
	temp = ft_strjoin("Speed scale: ", vtmp);
	offx = fdf->x_wind - (ft_strlen(temp) * 10) - 5;
	offy = fdf->y_wind - 25;
	mlx_string_put(fdf->mlx.mlx, fdf->mlx.win, offx, offy, 0x3399FF, temp);
	temp ? ft_memdel((void *)&temp) : 0;
	vtmp ? ft_memdel((void *)&vtmp) : 0;
}

/*
** Construct a string with the position in space of the grid then output it
** in the mlx window.
*/

void		ft_data_xyz(t_fdf *fdf, int offx)
{
	char	*rt;
	char	*temp;
	char	*vtmp;

	temp = NULL;
	vtmp = ft_itoa(fdf->x_pos);
	temp = ft_strjoin("X coord: ", vtmp);
	rt = ft_strjoin(temp, " Y coord: ");
	temp ? ft_memdel((void *)&temp) : 0;
	vtmp ? ft_memdel((void *)&vtmp) : 0;
	vtmp = ft_itoa(fdf->y_pos);
	temp = ft_strjoin(rt, vtmp);
	rt ? ft_memdel((void *)&rt) : 0;
	rt = ft_strjoin(temp, " Z coord: ");
	temp ? ft_memdel((void *)&temp) : 0;
	vtmp ? ft_memdel((void *)&vtmp) : 0;
	vtmp = ft_itoa(fdf->z_pos);
	temp = ft_strjoin(rt, vtmp);
	offx = (fdf->x_wind - (ft_strlen(temp) * 10)) / 2;
	mlx_string_put(fdf->mlx.mlx, fdf->mlx.win, offx, fdf->y_wind - 25, 0xCC0033, temp);
	temp ? ft_memdel((void *)&temp) : 0;
	vtmp ? ft_memdel((void *)&vtmp) : 0;
	rt ? ft_memdel((void *)&rt) : 0;
}

/*
** Commute the map size value to one string for the function above it.
*/

void		ft_data_msize(t_fdf *fdf)
{
	char	*temp;
	char	*vtmp;
	char	*rt;
	int		off_set;

	vtmp = ft_itoa(fdf->x_map);
	rt = ft_strjoin("X: ", vtmp);
	vtmp ? ft_memdel((void *)&vtmp) : 0;
	temp = ft_strjoin(rt, " Y: ");
	rt ? ft_memdel((void *)&rt) : 0;
	vtmp = ft_itoa(fdf->y_map);
	rt = ft_strjoin(temp, vtmp);
	off_set = (fdf->x_wind - (ft_strlen(rt) * 10)) / 2;
	mlx_string_put(fdf->mlx.mlx, fdf->mlx.win, off_set, 20, 0x00ceFF, rt);
	rt ? ft_memdel((void *)&rt) : 0;
	temp ? ft_memdel((void *)&temp) : 0;
	vtmp ? ft_memdel((void *)&vtmp) : 0;
}
