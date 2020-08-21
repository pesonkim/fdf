/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:47:16 by kpesonen          #+#    #+#             */
/*   Updated: 2019/11/11 20:58:58 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(next = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	new = next;
	while (lst->next)
	{
		lst = lst->next;
		temp = f(lst);
		if (!(next->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		next = next->next;
	}
	return (new);
}
