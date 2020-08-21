/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:51:27 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/20 12:51:29 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_view			*view_init(t_fdf *fdf)
{
	t_view		*view;

	if (!(view = (t_view*)malloc(sizeof(t_view))))
		ft_error("Malloc error");
	view->scale = fmin((WIN_W / fdf->map->width) * 0.6, \
	(WIN_H / fdf->map->height) * 0.6);
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	view->z_scale = 0.1;
	view->iso = 1;
	return (view);
}

t_vertex		vertex_init(int x, int y, t_fdf *fdf)
{
	t_vertex	vertex;

	vertex.x = x;
	vertex.y = y;
	vertex.z = fdf->map->matrix[y][x];
	vertex.color = vertex_color(vertex.z, fdf->map);
	project(&vertex.x, &vertex.y, &vertex.z, fdf);
	return (vertex);
}

t_map			*map_init(void)
{
	t_map		*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_error("Malloc error");
	map->matrix = NULL;
	map->width = 0;
	map->height = 0;
	map->z_min = 2147483647;
	map->z_max = -2147483648;
	map->pallette = 1;
	return (map);
}

t_fdf			*fdf_init(void)
{
	t_fdf		*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_error("Malloc error");
	fdf->map = map_init();
	fdf->mlx = mlx_init();
	fdf->view = NULL;
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, WIN_TITLE);
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->pixels = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->llen, &fdf->end);
	fdf->click = 0;
	fdf->wheel = 0;
	fdf->mouse_x = 0;
	fdf->mouse_y = 0;
	fdf->move_x = 0;
	fdf->move_y = 0;
	return (fdf);
}
