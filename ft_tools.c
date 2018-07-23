/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:17:08 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 14:17:09 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Error handling. Will print the error and exit the program.
*/

void	ft_error(char *msg)
{
	ft_putendl_fd("\e[1;31mKO\n", 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(0);
}

/*
** Defaults value when the map is first generated or if the reset key is pushed.
*/

void	ft_defaults(t_fdf *fdf)
{
	fdf->x_wind = ((fdf->x_map > fdf->y_map) ? fdf->x_map : fdf->y_map) * 10;
	(fdf->x_wind < 800) ? fdf->x_wind = 800 : (0);
	(fdf->x_wind > 1920) ? fdf->x_wind = 1920 : (0);
	fdf->y_wind = (fdf->x_wind * 9) / 16;
	fdf->zoom = fdf->y_wind / \
		((fdf->x_map > fdf->y_map) ? fdf->x_map : fdf->y_map);
	if (!fdf->zoom)
		fdf->zoom = 2;
	fdf->height = 1;
	fdf->x_pos = 30;
	fdf->y_pos = 0;
	fdf->z_pos = 0;
	fdf->color = 0xFFFFFF;
	fdf->sp = 3;
}

/*
** Key hooks function to process user inputs.
*/

int		ft_keyhook(int key, t_fdf *fdf)
{
	fdf->x_pos >= 360 ? fdf->x_pos -= 360 : 0;
	fdf->y_pos >= 360 ? fdf->y_pos -= 360 : 0;
	fdf->z_pos >= 360 ? fdf->z_pos -= 360 : 0;
	fdf->x_pos <= -360 ? fdf->x_pos += 360 : 0;
	fdf->y_pos <= -360 ? fdf->y_pos += 360 : 0;
	fdf->z_pos <= -360 ? fdf->z_pos += 360 : 0;
	(key == K_ESC) ? exit(0) : 0;
	(key == RESET) ? ft_defaults(fdf) : 0;
	(key == HPOS) ? fdf->height++ : 0;
	(key == HNEG && fdf->height) ? fdf->height-- : 0;
	(key == SPOS && fdf->sp < 10) ? fdf->sp++ : 0;
	(key == SNEG && fdf->sp) ? fdf->sp-- : 0;
	(key == XPOS) ? fdf->x_pos += fdf->sp : 0;
	(key == XNEG) ? fdf->x_pos -= fdf->sp : 0;
	(key == YPOS) ? fdf->y_pos += fdf->sp : 0;
	(key == YNEG) ? fdf->y_pos -= fdf->sp : 0;
	(key == RNEG) ? fdf->z_pos += fdf->sp : 0;
	(key == RPOS) ? fdf->z_pos -= fdf->sp : 0;
	((fdf->height * fdf->max_map) > (fdf->y_wind / 2)) ? fdf->height-- : 0;
	(!fdf->height) ? fdf->height++ : 0;
	ft_img_gen(fdf);
	return (0);
}

/*
** Support function: Check if the splitted line only contain numbers of it's
** an error and return 1 which will stock the parsing.
*/

int		ft_is_number(char *line)
{
	int t;

	t = 0;
	if (line && line[t] == '-')
		t++;
	while (line && line[t])
	{
		if ((line[t] >= 48 && line[t] <= 58) || \
			line[t] == 32 || line[t] == '-')
			t++;
		else
			return (1);
	}
	return (0);
}
