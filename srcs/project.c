/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:45:16 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/21 01:36:15 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int		prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int		prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = *z * cos(beta) - prev_x * sin(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int		prev_x;
	int		prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	transform_iso(int *x, int *y, int *z)
{
	int		prev_x;
	int		prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -*z + (prev_x + prev_y) * sin(0.523599);
}

void	project(int *x, int *y, int *z, t_fdf *fdf)
{
	*x *= fdf->view->scale;
	*y *= fdf->view->scale;
	*z *= fdf->view->scale * fdf->view->z_scale;
	*x -= fdf->view->scale * fdf->map->width / 2;
	*y -= fdf->view->scale * fdf->map->height / 2;
	rotate_x(y, z, fdf->view->alpha);
	rotate_y(x, z, fdf->view->beta);
	rotate_z(x, y, fdf->view->gamma);
	if (fdf->view->iso)
		transform_iso(x, y, z);
	*x += (WIN_W / 2) + fdf->move_x;
	*y += ((fdf->view->scale + WIN_H) / 2) + fdf->move_y;
}
