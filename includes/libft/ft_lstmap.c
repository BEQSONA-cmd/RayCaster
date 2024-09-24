/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:34:03 by btvildia          #+#    #+#             */
/*   Updated: 2023/12/04 13:56:34 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*ls;

	ls = NULL;
	if (!lst || !f || !del)
	{
		return (NULL);
	}
	while (lst)
	{
		a = malloc(sizeof(t_list));
		if (!a)
		{
			ft_lstclear(&ls, (*del));
			return (NULL);
		}
		a->content = f(lst->content);
		a->next = NULL;
		ft_lstadd_back(&ls, a);
		lst = lst->next;
	}
	return (ls);
}
