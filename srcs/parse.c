/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:01:08 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/18 16:06:05 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_values(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || (i == 0 && line[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	fill_matrix(t_map *map, int y, char *line)
{
	int		i;
	int		value;
	char	**points;

	i = 0;
	if (!(points = ft_strsplit(line, ' ')))
		ft_error("Malloc error");
	while (points[i] && (i < map->width))
	{
		if (!(check_values(points[i])))
			ft_error("Read error or invalid characters in file");
		value = ft_atoi(points[i]);
		map->matrix[y][i] = value;
		map->z_min = value < map->z_min ? value : map->z_min;
		map->z_max = value > map->z_max ? value : map->z_max;
		ft_strdel(&points[i]);
		i++;
	}
	free(points);
}

int		check_height(char *file)
{
	int		len;
	int		fd;
	int		ret;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		ft_error("Error opening file");
	len = 0;
	while ((ret = ft_get_next_line(fd, &line)) == 1)
	{
		len++;
		ft_strdel(&line);
	}
	if (ret < 0)
		ft_unknown_error();
	if (len == 0)
		ft_error("Invalid file");
	ft_strdel(&line);
	if (close(fd) < 0)
		ft_error("Error closing file");
	return (len);
}

int		check_width(char *file)
{
	int		len;
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		ft_error("Error opening file");
	ft_get_next_line(fd, &line);
	len = ft_count_words(line);
	if (len == 0)
		ft_error("Invalid file");
	ft_strdel(&line);
	if (close(fd) < 0)
		ft_error("Error closing file");
	return (len);
}

void	parse(char *file, t_map *map)
{
	int		y;
	int		fd;
	char	*line;

	map->height = check_height(file);
	map->width = check_width(file);
	if (!(fd = open(file, O_RDONLY)))
		ft_error("Error opening file");
	y = 0;
	if (!(map->matrix = (int**)malloc(sizeof(int*) * map->height)))
		ft_error("Malloc error");
	while (ft_get_next_line(fd, &line) == 1 && y < map->height)
	{
		if (!(map->matrix[y] = (int*)malloc(sizeof(int) * map->width)))
			ft_error("Malloc error");
		if (ft_count_words(line) != map->width)
			ft_error("Invalid file");
		fill_matrix(map, y, line);
		y++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd) < 0)
		ft_error("Error closing file");
	return ;
}
