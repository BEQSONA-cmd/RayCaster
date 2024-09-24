/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:34:07 by btvildia          #+#    #+#             */
/*   Updated: 2024/01/27 12:52:38 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

int	ft_size(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

size_t	ft_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**a;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	a = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	while (j < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		a[j] = ft_substr(s, i, ft_size(s, c, i));
		if (!a[j])
		{
			ft_free(a, j);
			return (NULL);
		}
		i = i + ft_size(s, c, i);
		j++;
	}
	a[j] = 0;
	return (a);
}
