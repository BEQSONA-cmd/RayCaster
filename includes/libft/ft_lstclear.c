/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:37:18 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/04 13:56:11 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*node;

	if (!lst || !del)
	{
		return ;
	}
	a = *lst;
	while (a != NULL)
	{
		node = a->next;
		del(a->content);
		free(a);
		a = node;
	}
	*lst = NULL;
}
