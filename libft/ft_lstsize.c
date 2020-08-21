/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:44:26 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/12 13:50:22 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	count;

	count = 0;
	if (!lst)
		return (count);
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
