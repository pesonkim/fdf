/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpesonen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:15:32 by kpesonen          #+#    #+#             */
/*   Updated: 2020/08/07 12:27:00 by kpesonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char const *s)
{
	int	word;
	int	count;

	count = 0;
	word = 0;
	while (*s)
	{
		while (*s && *s != ' ' && *s != '\n' && *s != '\t')
		{
			s++;
			word = 1;
		}
		if (word == 1)
		{
			count++;
			word = 0;
		}
		if (*s)
			s++;
	}
	return (count);
}
