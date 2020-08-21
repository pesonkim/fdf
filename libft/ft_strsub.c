/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:55:43 by kpesonen          #+#    #+#             */
/*   Updated: 2019/10/30 19:17:36 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = (size_t)start;
	j = 0;
	if (!(sub = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	return (sub);
}
