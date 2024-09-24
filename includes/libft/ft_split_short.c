/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:55:14 by btvildia          #+#    #+#             */
/*   Updated: 2024/01/27 12:55:30 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char *a)
{
	int		i;
	int		j;
	int		x;
	char	**c;

	i = 0;
	j = 0;
	x = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		if (a[i])
			j++;
		while (a[i] && a[i] != ' ')
			i++;
	}
	c = malloc(sizeof(char *) * j + 1);
	i = 0;
	j = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		j = i;
		while (a[i] && a[i] != ' ')
			i++;
		if (i > j)
		{
			c[x] = malloc(sizeof(char) * (i - j) + 1);
			ft_strncpy(c[x], &a[j], i - j);
			x++;
		}
	}
	c[x] = NULL;
	return (c);
}
