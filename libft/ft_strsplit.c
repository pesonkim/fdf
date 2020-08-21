/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:35:16 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/10 18:42:18 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cw(char const *s, char c)
{
	int	words;

	words = 0;
	if (*s != c && *s)
	{
		words++;
		s++;
	}
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				words++;
		}
		s++;
	}
	return (words);
}

static int	ft_cl(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	if (!s || !(arr = (char**)malloc(sizeof(char*) * (ft_cw(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			j = 0;
			if (!(arr[i] = (char*)malloc(sizeof(char) * (ft_cl(s, c) + 1))))
				return (NULL);
			while (*s != c && *s)
				arr[i][j++] = (char)*s++;
			arr[i][j] = '\0';
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
