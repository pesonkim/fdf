/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:08:45 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/07 13:12:18 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)s;
	if (n != 0)
	{
		while (n-- > 0)
		{
			if (*p == (unsigned char)c)
				return (p);
			p++;
		}
	}
	return (NULL);
}
