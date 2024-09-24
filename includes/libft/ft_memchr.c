/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:13:02 by btvildia          #+#    #+#             */
/*   Updated: 2023/11/19 21:23:06 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a = s;
	unsigned int		i;

	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (a[i] == c)
		{
			return ((void *)&a[i]);
		}
		i++;
	}
	return (NULL);
}
