/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:49:14 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/21 00:06:12 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			gradient(int start, int end, double percent)
{
	return ((1 - percent) * start + percent * end);
}

int			pixel_color(t_vertex pixel, t_vertex begin, t_vertex end)
{
	int		r;
	int		g;
	int		b;
	int		color;
	double	p;

	if (pixel.color == end.color)
		return (pixel.color);
	if ((end.x - begin.x) > (end.y - begin.y))
		p = percent(begin.x, end.x, pixel.x);
	else
		p = percent(begin.y, end.y, pixel.y);
	r = gradient((begin.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	g = gradient((begin.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	b = gradient(begin.color & 0xFF, end.color & 0xFF, p);
	color = 0;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

int			vertex_color(int z, t_map *map)
{
	double	p;

	p = percent(map->z_min, map->z_max, z);
	if (p < 0.1)
		return (map->pallette > 0 ? COLORA : COLOR1);
	else if (p < 0.2)
		return (map->pallette > 0 ? GRADA : GRAD1);
	else if (p < 0.3)
		return (map->pallette > 0 ? GRADB : GRAD2);
	else if (p < 0.4)
		return (map->pallette > 0 ? GRADC : GRAD3);
	else if (p < 0.5)
		return (map->pallette > 0 ? GRADD : GRAD4);
	else if (p < 0.6)
		return (map->pallette > 0 ? GRADE : GRAD5);
	else if (p < 0.7)
		return (map->pallette > 0 ? GRADF : GRAD6);
	else if (p < 0.8)
		return (map->pallette > 0 ? GRADG : GRAD7);
	else if (p < 0.9)
		return (map->pallette > 0 ? GRADH : GRAD8);
	else
		return (map->pallette > 0 ? COLORB : COLOR2);
}
