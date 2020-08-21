/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:09:13 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/11 22:17:45 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (n-- > 0)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
