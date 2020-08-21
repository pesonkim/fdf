/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:16:56 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/08 15:30:21 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = fdf->pixels + ((y * fdf->llen) + (x * 4));
		*(int*)dst = color;
	}
}

void	plot_line(t_vertex begin, t_vertex end, t_fdf *fdf)
{
	t_vertex	cur;
	t_vertex	delta;
	t_vertex	sign;
	int			err[2];

	cur = begin;
	delta.x = ft_abs(end.x - begin.x);
	delta.y = -ft_abs(end.y - begin.y);
	sign.x = begin.x < end.x ? 1 : -1;
	sign.y = begin.y < end.y ? 1 : -1;
	err[0] = delta.x + delta.y;
	while (cur.x != end.x || cur.y != end.y)
	{
		img_pixel_put(fdf, cur.x, cur.y, pixel_color(cur, begin, end));
		if ((err[1] = 2 * err[0]) >= delta.y)
		{
			err[0] += delta.y;
			cur.x += sign.x;
		}
		if (err[1] <= delta.x)
		{
			err[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void	restart(t_fdf *fdf)
{
	int		*img;
	int		i;

	img = (int*)(fdf->pixels);
	i = 0;
	while (i < WIN_W * WIN_H)
	{
		img[i] = BACKGROUND;
		i++;
	}
	draw(fdf);
}

void	draw(t_fdf *fdf)
{
	int x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if ((x + 1) < fdf->map->width)
			{
				plot_line(vertex_init(x, y, fdf), \
				vertex_init(x + 1, y, fdf), fdf);
			}
			if ((y + 1) < fdf->map->height)
				plot_line(vertex_init(x, y, fdf), \
				vertex_init(x, y + 1, fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
