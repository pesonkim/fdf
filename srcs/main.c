/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:16:56 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/18 16:11:12 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		if (!(ft_strstr(av[1], ".fdf")))
			ft_error("Invalid file");
		fdf = fdf_init();
		parse(av[1], fdf->map);
		fdf->view = view_init(fdf);
		draw(fdf);
		mlx_hook(fdf->win, 2, 0, key_press, fdf);
		mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
		mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
		mlx_hook(fdf->win, 6, 0, mouse_motion, fdf);
		mlx_hook(fdf->win, 17, 0, window_destroy, (void*)0);
		mlx_loop(fdf->mlx);
	}
	else
		display_usage();
	return (0);
}
