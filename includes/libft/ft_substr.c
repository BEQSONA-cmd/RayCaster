/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:18:21 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/02 16:44:14 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*a;

	i = 0;
	j = ft_strlen(s);
	if (start >= j)
	{
		start = 0;
		len = 0;
	}
	if (len > j - start)
	{
		len = j - start;
	}
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
