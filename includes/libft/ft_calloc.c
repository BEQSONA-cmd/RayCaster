/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:38:08 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/04 14:04:01 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	void			*a;

	if (count == 0 || size == 0)
	{
		return (malloc(0));
	}
	i = count * size;
	a = malloc(i);
	if (a == NULL)
	{
		return (NULL);
	}
	ft_memset(a, 0, i);
	return (a);
}
