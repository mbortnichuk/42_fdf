/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:28:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:28:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Put the point to the image bit per bit from f->color, which is white
*/

int				ft_mlx_img(t_pxl a, t_fdf *fdf)
{
	char	*px;
	int		bpp;
	int		end;
	int		length;
	int		i;

	if (a.x >= fdf->x_wind || a.y >= fdf->y_wind || a.x < 0 || a.y < 0)
		return (1);
	i = 0;
	px = mlx_get_data_addr(fdf->mlx.img, &bpp, &length, &end);
	if (end == 0)
		while (i != bpp / 8)
		{
			px[a.y * length + a.x * (bpp / 8) +
				i++] = (0x000000FF & fdf->color);
			px[a.y * length + a.x * (bpp / 8) +
				i++] = (0x0000FF00 & fdf->color) >> 8;
			px[a.y * length + a.x * (bpp / 8) +
				i++] = (0x00FF0000 & fdf->color) >> 16;
			px[a.y * length + a.x * (bpp / 8) +
				i++] = (0xFF000000 & fdf->color) >> 24;
		}
	return (0);
}
