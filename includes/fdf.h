/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:13:55 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/18 16:12:36 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "keys.h"
# define WIN_W 1500
# define WIN_H 900
# define WIN_TITLE "fdf"
# define COLOR1 0xFF66CC
# define GRAD1 0xEE77BB
# define GRAD2 0xDD88AA
# define GRAD3 0xCC9999
# define GRAD4 0xBBAA88
# define GRAD5 0xAABB77
# define GRAD6 0x99CC66
# define GRAD7 0x88DD55
# define GRAD8 0x77EE44
# define COLOR2 0x66FF33
# define COLORA 0x33CCFF
# define GRADA 0x44BBF4
# define GRADB 0x55AAE8
# define GRADC 0x6699DD
# define GRADD 0x7788D2
# define GRADE 0x8877C6
# define GRADF 0x9966BB
# define GRADG 0xAA55B0
# define GRADH 0xBB44A4
# define COLORB 0xCC3399

# define BACKGROUND 0x000000

typedef	struct		s_vertex
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_vertex;

typedef	struct		s_map
{
	int				width;
	int				height;
	int				z_min;
	int				z_max;
	int				**matrix;
	int				pallette;
}					t_map;

typedef	struct		s_view
{
	int				scale;
	double			alpha;
	double			beta;
	double			gamma;
	double			z_scale;
	int				iso;
}					t_view;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixels;
	int				bpp;
	int				llen;
	int				end;
	t_map			*map;
	t_view			*view;
	int				click;
	int				wheel;
	int				mouse_x;
	int				mouse_y;
	int				move_x;
	int				move_y;
}					t_fdf;

t_fdf				*fdf_init(void);
t_view				*view_init(t_fdf *fdf);
t_vertex			vertex_init(int x, int y, t_fdf *fdf);
int					vertex_color(int z, t_map *map);
int					pixel_color(t_vertex pixel, t_vertex begin, t_vertex end);
void				draw(t_fdf *fdf);
void				restart(t_fdf *fdf);
void				project(int *x, int *y, int *z, t_fdf *fdf);
void				parse(char *av, t_map *map);
void				ft_error(char *s);
void				ft_unknown_error(void);
void				display_usage(void);
int					window_destroy(void);
int					key_press(int keycode, t_fdf *fdf);
int					mouse_press(int button, int x, int y, t_fdf *fdf);
int					mouse_release(int button, int x, int y, t_fdf *fdf);
int					mouse_motion(int x, int y, t_fdf *fdf);

#endif
