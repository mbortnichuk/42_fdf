/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:44:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/22 13:44:57 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "fcntl.h"
# include <math.h>
# include <mlx.h>

/*
** Window size automatically determined by the map
** Autozoom level per map size
** Rotation by the axis X (Num 4 and Num 6)
** Rotation by the axis Y (Num 2 and Num 8)
** Rotation by the axis Z (Num 1 and Num 3)
** Adjustable height capped by the highest point in the map (Num 7 and Num 9)
** Movement speed adjustable (Num minus and Num plus)
** Telemetric data in the mlx window
** UI Guide on console
** Keyhold support
** View reset to defaults (Num 5)
*/

/*
** Key mapping from raw value
*/

# define XPOS		91
# define XNEG		84
# define YPOS		88
# define YNEG		86
# define RPOS		85
# define RNEG		83
# define SPOS		69
# define SNEG		78
# define HPOS		92
# define HNEG		89
# define RESET		87

typedef struct s_line	t_line;
typedef struct s_pxl	t_pxl;
typedef struct s_mlx	t_mlx;
typedef struct s_fdf	t_fdf;

/*
** Data structures.
*/

struct					s_line
{
	float a;
	float b;
	float c;
};

struct					s_pxl
{
	int x;
	int y;
	int h;
	int x_1;
	int y_1;
	int h_1;
};

struct					s_mlx
{
	void *mlx;
	void *win;
	void *img;
};

struct					s_fdf
{
	char		*name;
	t_mlx		mlx;
	int			x_wind;
	int			y_wind;
	t_pxl		**map;
	int			x_map;
	int			y_map;
	int			max_map;
	int			height;
	int			zoom;
	int			sp;
	int			color;
	float		x_pos;
	float		y_pos;
	float		z_pos;
};

/*
** ft_calc.c
*/

void					ft_shifting(t_pxl *pix, t_fdf *fdf);
void					ft_recalc(int x, int y, t_fdf *fdf);

/*
** ft_draw.c
*/

void					ft_straight(t_pxl a, t_pxl b, t_fdf *fdf, int s);
void					ft_diagonal_y(t_pxl step, t_pxl pnt, \
							t_fdf *fdf, float j);
void					ft_diagonal_x(t_pxl step, t_pxl pnt, \
							t_fdf *fdf, float j);
void					ft_join_pixel(t_fdf *fdf, t_pxl pix1, t_pxl pix2);

/*
** ft_gen_img.c
*/

void					ft_img_gen(t_fdf *fdf);

/*
** ft_img.c
*/

int						ft_mlx_img(t_pxl a, t_fdf *fdf);

/*
** ft_parse.c
*/

void					ft_filler(int x, int y, t_fdf *fdf);
void					ft_alloc(int i, t_fdf *fdf);

/*
** ft_screen.c
*/

void					ft_data_var(int offx, int offy, t_fdf *fdf);
void					ft_data_xyz(int offx, t_fdf *fdf);
void					ft_data_msize(t_fdf *fdf);
int						ft_sstrlen(char **str);
void					ft_sstrdel(char **str);

/*
** ft_tools.c
*/

void					ft_error(char *msg);
void					ft_defaults(t_fdf *fdf);
int						ft_keyhook(int key, t_fdf *fdf);
int						ft_is_number(char *line);

/*
** main.c
*/

void					ft_parser(t_fdf *fdf);
void					ft_screeninfo(t_fdf *fdf);

#endif
