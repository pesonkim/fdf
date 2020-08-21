/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:51:56 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/13 13:03:01 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (slen);
	if (dstsize < dlen)
		slen += dstsize;
	else
		slen += dlen;
	while (src[i] != '\0' && dlen < (dstsize - 1) && dst != src)
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (slen);
}
