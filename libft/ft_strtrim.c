/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:06:38 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/10 20:59:02 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] != '\0' &&
	(s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while (len > 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
