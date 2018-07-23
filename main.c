/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:47:28 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 13:47:29 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Open the file and determine the map size while checking if it only contain
** numbers and if the lines are equal. If not, the parsing stop and fdf exit.
*/

void			ft_parser(t_fdf *fdf)
{
	char	**splitt;
	char	*str;
	char	*temp;
	int		file_descr;

	if ((file_descr = open(fdf->name, O_RDONLY)) < 0)
		ft_error("Cannot open file given as an argument.");
	if ((read(file_descr, NULL, 0)) < 0)
		ft_error("Cannot open file given as an argument.");
	while (get_next_line(file_descr, &str))
	{
		temp = ft_strtrim(str);
		splitt = ft_strsplit(temp, ' ');
		str ? ft_memdel((void *)&str) : 0;
		ft_is_number(temp) ? \
			ft_error("Not a number has been found in file.") : (0);
		temp ? ft_memdel((void *)&temp) : 0;
		(fdf->x_map == 0) ? fdf->x_map = ft_sstrlen(splitt) : 0;
		if (fdf->x_map != ft_sstrlen(splitt))
			ft_error("Lines in file are not equal.");
		splitt ? ft_sstrdel(splitt) : 0;
		fdf->y_map++;
	}
	close(file_descr);
	ft_alloc(0, fdf);
}

/*
** Print on screen informations: map name, map size, height and zoom.
*/

void			ft_screeninfo(t_fdf *fdf)
{
	char	*temp;
	int		off_set;

	temp = NULL;
	temp = ft_strjoin("MAP selected: ", fdf->name);
	off_set = (fdf->x_wind - (ft_strlen(temp) * 10)) / 2;
	mlx_string_put(fdf->mlx.mlx, fdf->mlx.win, off_set, 0, 0x00FF00, temp);
	temp ? ft_memdel((void *)&temp) : (0);
	ft_data_msize(fdf);
	ft_data_xyz(0, fdf);
	ft_data_var(0, 0, fdf);
}

static void		ft_instructions(void)
{
	ft_putendl("\e[32mOK\e[0m");
	ft_printf(CYN"\n\t    Press [ESC] to quit FDF\n"RC);
}

/*
** Starting point of program.
*/

int				main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_error("Usage: ./fdf [filename.fdf]");
	fdf.name = ft_strdup(av[1]);
	fdf.x_map = 0;
	fdf.y_map = 0;
	fdf.max_map = 0;
	ft_printf(GRN"\t\tParsing..."RC);
	ft_parser(&fdf);
	ft_defaults(&fdf);
	fdf.mlx.mlx = mlx_init();
	fdf.mlx.win = mlx_new_window(fdf.mlx.mlx, \
		fdf.x_wind, fdf.y_wind, "fdf by mbortnic");
	ft_img_gen(&fdf);
	ft_instructions();
	mlx_hook(fdf.mlx.win, 2, (1L << 0), &ft_keyhook, &fdf);
	mlx_loop(fdf.mlx.mlx);
	system("leaks fdf");
	return (0);
}
