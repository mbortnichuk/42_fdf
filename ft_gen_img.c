/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:29:38 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:29:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Cycle through the array to commute all the point into a new image. Prior to
** this, it will call the ft_recalc function to recalculate the new coordinate
** of the arrays. Once the image have been generated, it will display it,
** destroy the image and call the function for the onscreen infos.
*/

void		ft_img_gen(t_fdf *fdf)
{
	int x;
	int y;

	ft_recalc(fdf, 0, 0);
	fdf->mlx.img = mlx_new_image(fdf->mlx.mlx, fdf->x_wind, fdf->y_wind);
	y = 0;
	while (y < fdf->y_map)
	{
		x = 0;
		while (x < fdf->x_map)
		{
			if (y != fdf->y_map - 1)
				ft_join_pixel(fdf, fdf->map[y][x], fdf->map[y + 1][x]);
			if (x != fdf->x_map - 1)
				ft_join_pixel(fdf, fdf->map[y][x], fdf->map[y][x + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img);
	ft_screeninfo(fdf);
}
