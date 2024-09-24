/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:58:20 by btvildia          #+#    #+#             */
/*   Updated: 2023/11/22 18:10:22 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;
	size_t	y;

	x = ft_strlen(dst);
	y = ft_strlen(src);
	i = 0;
	if (dstsize <= x)
	{
		return (dstsize + y);
	}
	while (src[i] != '\0' && (x + i) < (dstsize - 1))
	{
		dst[x + i] = src[i];
		i++;
	}
	dst[x + i] = '\0';
	return (x + y);
}
