/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:45:13 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/12 00:27:01 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next;

	if (!alst || !(*alst) || !del)
		return ;
	temp = *alst;
	while (temp)
	{
		next = temp->next;
		ft_lstdelone(&temp, del);
		temp = next;
	}
	*alst = NULL;
}
