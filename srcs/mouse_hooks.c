/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:30:50 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/21 02:19:47 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_motion(int x, int y, t_fdf *fdf)
{
	int		prev_x;
	int		prev_y;

	prev_x = fdf->mouse_x;
	prev_y = fdf->mouse_y;
	fdf->mouse_x = x;
	fdf->mouse_y = y;
	if (fdf->click)
	{
		fdf->move_x += (fdf->mouse_x - prev_x);
		fdf->move_y += (fdf->mouse_y - prev_y);
		restart(fdf);
	}
	else if (fdf->wheel)
	{
		fdf->view->beta += (fdf->mouse_x - prev_x) * 0.003;
		fdf->view->alpha += (fdf->mouse_y - prev_y) * 0.003;
		restart(fdf);
	}
	return (0);
}

void	zoom(int button, t_fdf *fdf)
{
	if (button == 5)
	{
		fdf->view->scale -= 1;
		restart(fdf);
	}
	else if (button == 4)
	{
		fdf->view->scale += 1;
		restart(fdf);
	}
}

int		mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 1)
		fdf->click = 0;
	else if (button == 3)
		fdf->wheel = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 1)
		fdf->click = 1;
	else if (button == 2)
	{
		fdf->map->pallette = (fdf->map->pallette > 0) ? 0 : 1;
		restart(fdf);
	}
	else if (button == 3)
		fdf->wheel = 1;
	else if (button == 4 || button == 5)
		zoom(button, fdf);
	return (0);
}
