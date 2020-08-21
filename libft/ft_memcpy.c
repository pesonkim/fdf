/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:43:52 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/11 21:57:41 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (!n || dst == src)
		return (dst);
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
