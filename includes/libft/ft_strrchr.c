/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:28:01 by btvildia          #+#    #+#             */
/*   Updated: 2023/11/22 17:40:51 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*l = NULL;

	c = (char)c;
	while (1)
	{
		if (*s == c)
		{
			l = s;
		}
		if (*s == '\0')
		{
			break ;
		}
		s++;
	}
	return ((char *)l);
}
