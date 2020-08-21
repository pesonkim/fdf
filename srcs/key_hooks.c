/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:57:48 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/08 15:30:37 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		window_destroy(void)
{
	exit(1);
}

void	projection_change(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ANSI_1)
	{
		fdf->view->iso = 1;
		fdf->view->alpha = 0;
		fdf->view->beta = 0;
		fdf->view->gamma = 0;
		restart(fdf);
	}
	else if (keycode == KEY_ANSI_2)
	{
		fdf->view->iso = 0;
		fdf->view->alpha = 0;
		fdf->view->beta = 0;
		fdf->view->gamma = 0;
		restart(fdf);
	}
}

void	reset_view(t_fdf *fdf)
{
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->view->alpha = 0;
	fdf->view->beta = 0;
	fdf->view->gamma = 0;
	fdf->view->scale = fmin((WIN_W / fdf->map->width) * 0.6, \
	(WIN_H / fdf->map->height) * 0.6);
	restart(fdf);
}

int		key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	else if (keycode == KEY_ANSI_Q)
	{
		fdf->view->z_scale -= 0.01;
		restart(fdf);
	}
	else if (keycode == KEY_ANSI_E)
	{
		fdf->view->z_scale += 0.01;
		restart(fdf);
	}
	else if (keycode == KEY_ANSI_R)
		reset_view(fdf);
	else if (keycode == KEY_ANSI_1 || keycode == KEY_ANSI_2)
		projection_change(keycode, fdf);
	return (0);
}
