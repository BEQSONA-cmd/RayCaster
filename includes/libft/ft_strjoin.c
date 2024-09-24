/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:15:36 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/02 17:22:04 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	x;
	unsigned int	y;
	int				i;
	char			*a;

	i = 0;
	x = ft_strlen(s1);
	y = ft_strlen(s2);
	a = malloc(x + y + 1);
	if (!a)
	{
		return (NULL);
	}
	ft_strlcpy(a, s1, (x + y + 1));
	while (s2[i] != '\0')
	{
		a[x + i] = s2[i];
		i++;
	}
	a[x + i] = '\0';
	return (a);
}
