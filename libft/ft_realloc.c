/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:42:04 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/18 13:15:01 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t newsize)
{
	void	*new;

	if (!src)
		return (NULL);
	if (!(new = ft_memalloc(newsize)))
		return (NULL);
	new = ft_memcpy(new, src, newsize / 2);
	free(src);
	return (new);
}
