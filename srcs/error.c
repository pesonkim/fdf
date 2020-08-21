/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:37:40 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/18 15:57:01 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_usage(void)
{
	ft_putendl("Usage: ./fdf map_file.fdf");
}

void	ft_error(char *s)
{
	ft_putendl(s);
	display_usage();
	exit(1);
}

void	ft_unknown_error(void)
{
	perror("Error");
	display_usage();
	exit(1);
}
