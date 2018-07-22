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
** Key mapping from raw value mapped below
*/

# define XPOS		K_NUM8
# define XNEG		K_NUM2
# define YPOS		K_NUM6
# define YNEG		K_NUM4
# define RPOS		K_NUM3
# define RNEG		K_NUM1
# define SPOS		K_NUM_P
# define SNEG		K_NUM_N
# define HPOS		K_NUM9
# define HNEG		K_NUM7
# define RESET		K_NUM5

/*
** RAW key values
*/

# define K_NUM1		83
# define K_NUM2		84
# define K_NUM3		85
# define K_NUM4		86
# define K_NUM5		87
# define K_NUM6		88
# define K_NUM7		89
# define K_NUM8		91
# define K_NUM9		92
# define K_NUM_P	69
# define K_NUM_N	78
# define K_ESC		53
# define K_ARU		126

typedef struct s_line t_line;
typedef struct s_pxl t_pxl;
typedef struct s_mlx t_mlx;
typedef struct s_fdf t_fdf;

/*
** Data structures.
*/

struct s_line
{
	float a;
	float b;
	float c;
};

struct s_pxl
{
	int x;
	int y;
	int h;
	int x1;
	int y1;
	int h1;
};

struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
};

struct s_fdf
{
	char		*name; //
	t_mlx		mlx; //
	int			x_wind; //
	int			y_wind; //
	t_pxl		**map; //
	int			x_map; //
	int			y_map; //
	int			max_map; //
	int			height; //
	int			zoom; //
	int			sp;
	int			color;
	float		x_pos; //
	float		y_pos; //
	float		z_pos; //
};

/*
** ft_calc.c
*/

void	ft_shifting(t_fdf *fdf, t_pxl *pix);
void	ft_recalc(t_fdf *fdf, int x, int y);

/*
** ft_draw.c
*/

void	ft_straight(t_fdf *fdf, t_pxl a, t_pxl b, int s);
void	ft_diagonal_y(t_fdf *fdf, t_pxl step, t_pxl pnt, float j);
void	ft_diagonal_x(t_fdf *fdf, t_pxl step, t_pxl pnt, float j);
void	ft_join_pixel(t_fdf *fdf, t_pxl pix1, t_pxl pix2);

/*
** ft_gen_img.c
*/

void	ft_img_gen(t_fdf *fdf);

/*
** ft_img.c
*/

int		ft_mlx_img(t_fdf *fdf, t_pxl a);

/*
** ft_parse.c
*/

void	ft_filler(t_fdf *fdf, int x, int y);
void	ft_alloc(t_fdf *fdf, int i);

/*
** ft_screen.c
*/

void	ft_data_var(t_fdf *fdf, int offx, int offy);
void	ft_data_xyz(t_fdf *fdf, int offx);
void	ft_data_msize(t_fdf *fdf);

/*
** ft_tools.c
*/

void	ft_error(char *msg);
void	ft_defaults(t_fdf *fdf);
int		ft_keyhook(int key, t_fdf *fdf);
int		ft_is_number(char *line);

/*
** main.c
*/

void	ft_parser(t_fdf *fdf);
void	ft_screeninfo(t_fdf *fdf);
int		ft_sstrlen(char **str);
void	ft_sstrdel(char **str);

#endif
