/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:28:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:28:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Shift the point with the value from the user input. Handling the rotation
** in all axis with fdf->x_pos, fdf->y_pos and fdf->x_pos.
*/

void	ft_shifting(t_pxl *pix, t_fdf *fdf)
{
	float	angle;
	float	x[2];

	angle = (3.14159265 * fdf->x_pos) / 180;
	x[0] = pix->h * cos(angle) + pix->y_1 * sin(angle);
	x[1] = pix->y_1 * cos(angle) - pix->h * sin(angle);
	pix->h = round(x[0]);
	pix->y_1 = round(x[1]);
	angle = (3.14159265 * fdf->y_pos) / 180;
	x[0] = pix->x_1 * cos(angle) + pix->h * sin(angle);
	x[1] = pix->h * cos(angle) - pix->x_1 * sin(angle);
	pix->x_1 = round(x[0]);
	pix->h = round(x[1]);
	angle = (3.14159265 * fdf->z_pos) / 180;
	x[0] = pix->x_1 * cos(angle) + pix->y_1 * sin(angle);
	x[1] = pix->y_1 * cos(angle) - pix->x_1 * sin(angle);
	pix->x_1 = round(x[0]);
	pix->y_1 = round(x[1]);
}

/*
** Recalculate all the points.
*/

void	ft_recalc(int x, int y, t_fdf *fdf)
{
	t_line	temp;

	y = 0;
	while (y < fdf->y_map)
	{
		x = 0;
		while (x < fdf->x_map)
		{
			fdf->map[y][x].x_1 = fdf->zoom * (x - fdf->x_map / 2);
			fdf->map[y][x].y_1 = fdf->zoom * (y - fdf->y_map / 2);
			fdf->map[y][x].h = fdf->map[y][x].h_1 * fdf->height;
			ft_shifting(&fdf->map[y][x], fdf);
			temp.a = fdf->map[y][x].x_1;
			temp.b = fdf->map[y][x].y_1;
			temp.c = fdf->map[y][x].h - 1000;
			fdf->map[y][x].x = (temp.a / temp.c) * (250 - 1000);
			fdf->map[y][x].x += fdf->x_wind / 2;
			fdf->map[y][x].y = (temp.b / temp.c) * (250 - 1000);
			fdf->map[y][x].y += fdf->y_wind / 2;
			x++;
		}
		y++;
	}
}
