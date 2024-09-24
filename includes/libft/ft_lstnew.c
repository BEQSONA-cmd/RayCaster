/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:15:53 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/03 22:19:28 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (a == NULL)
	{
		return (NULL);
	}
	if (!content)
	{
		a->content = NULL;
	}
	else
	{
		a->content = content;
	}
	a->next = NULL;
	return (a);
}
