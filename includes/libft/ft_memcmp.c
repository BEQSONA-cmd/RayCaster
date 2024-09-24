/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:19:56 by btvildia          #+#    #+#             */
/*   Updated: 2023/11/23 21:03:54 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	const char		*a = s1;
	const char		*b = s2;

	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
		{
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		}
		i++;
	}
	return (0);
}
