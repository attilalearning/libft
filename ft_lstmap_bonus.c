/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:02:09 by aistok            #+#    #+#             */
/*   Updated: 2024/05/13 19:35:50 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list and the list related functions (ft_lst...) */
#include "libft.h"
/* used for malloc, free and NULL */
#include <stdlib.h>

/*
 *	Description
 *	Iterates the list ’lst’ and applies the function ’f’ on the content of
 *	each node. Creates a new list resulting of the successive applications
 *	of the function ’f’. The ’del’ function is used to delete the content
 *	of a node if needed.
 *
 * 	Parameters
 * 	lst: The address of a pointer to a node.
 * 	f: The address of the function used to iterate on the list.
 * 	del: The address of the function used to delete the content of a node
 * 	if needed.
 *
 * 	Return value
 * 	The new list.
 * 	NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
