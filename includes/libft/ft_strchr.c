/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:38:35 by btvildia          #+#    #+#             */
/*   Updated: 2023/11/19 22:41:09 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (1)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		if (*s == '\0')
		{
			break ;
		}
		s++;
	}
	return (NULL);
}
