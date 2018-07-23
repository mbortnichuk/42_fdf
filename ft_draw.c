/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:30:24 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:30:25 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** If the two point are straight, the function will put pixel per pixel
** until the two point are met.
*/

void	ft_straight(t_pxl a, t_pxl b, t_fdf *fdf, int s)
{
	if (a.y == b.y)
	{
		s = (a.x > b.x) ? -1 : 1;
		while (a.x != b.x)
		{
			ft_mlx_img(a, fdf);
			a.x += s;
		}
		ft_mlx_img(a, fdf);
	}
	else
	{
		s = (a.y > b.y) ? -1 : 1;
		while (a.y != b.y)
		{
			ft_mlx_img(a, fdf);
			a.y += s;
		}
		ft_mlx_img(a, fdf);
	}
}

/*
** If the two point are in a diagonal, the function will calculate the
** length and draw pixel per pixel while shifting the place to account the
** diagonal needed for the two pixel to meet.
*/

void	ft_diagonal_y(t_pxl step, t_pxl pnt, t_fdf *fdf, float j)
{
	float	st_point;
	t_pxl	a;
	int		i;
	int		n;

	i = step.x;
	n = step.y;
	st_point = pnt.x;
	a.x = st_point;
	a.y = i;
	ft_mlx_img(a, fdf);
	while (i <= n)
	{
		a.x = st_point;
		a.y = i;
		ft_mlx_img(a, fdf);
		st_point += j;
		i++;
	}
}

/*
** If the two point are in a diagonal, the function will calculate the
** length and draw pixel per pixel while shifting the place to account the
** diagonal needed for the two pixel to meet.
*/

void	ft_diagonal_x(t_pxl step, t_pxl pnt, t_fdf *fdf, float j)
{
	float	st_point;
	t_pxl	a;
	int		i;
	int		n;

	i = step.x;
	n = step.y;
	st_point = pnt.y;
	a.x = i;
	a.y = st_point;
	ft_mlx_img(a, fdf);
	while (i <= n)
	{
		a.x = i;
		a.y = st_point;
		ft_mlx_img(a, fdf);
		st_point += j;
		i++;
	}
}

/*
** The function get two point from the array and calculate the diagonal to
** join them. If the two points make a straight line (identical position in x
** and y), the function ft_straight is called. If not, the function
** fdf_diagonal is called. All of these will put pixel per pixel the result
** line in the image by calling ft_mlx_img function.
*/

void	ft_join_pixel(t_fdf *fdf, t_pxl pix1, t_pxl pix2)
{
	t_pxl	shift;
	float	m;

	if (pix1.x == pix2.x || pix1.y == pix2.y)
		ft_straight(pix1, pix2, fdf, 0);
	else if (abs(pix1.x - pix2.x) > abs(pix1.y - pix2.y))
	{
		m = ((float)(pix2.y - pix1.y)) / (pix2.x - pix1.x);
		shift.x = (int)fmin(pix1.x, pix2.x);
		shift.y = (int)fmax(pix1.x, pix2.x);
		ft_diagonal_x(shift, (pix1.x < pix2.x) ? pix1 : pix2, fdf, m);
	}
	else
	{
		m = ((float)(pix2.x - pix1.x)) / (pix2.y - pix1.y);
		shift.x = (int)fmin(pix1.y, pix2.y);
		shift.y = (int)fmax(pix1.y, pix2.y);
		ft_diagonal_y(shift, (pix1.y < pix2.y) ? pix1 : pix2, fdf, m);
	}
}
