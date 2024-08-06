/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:13:58 by aistok            #+#    #+#             */
/*   Updated: 2024/05/07 22:45:32 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list */
#include "libft.h"
/* used for free and NULL */
#include <stdlib.h>

/*
 *	Description
 *	Deletes and frees the given node and every successor of that node, using
 *	the function ’del’ and free(3). Finally, the pointer to the list must be
 *	set to NULL.
 *
 *	Parameters
 *	lst: The address of a pointer to a node.
 *	del: The address of the function used to delete the content of the node.
 *
 *	Return value
 *	None.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*next_node;

	if (!lst || !(*lst) || !del)
		return ;
	list = *lst;
	while (list)
	{
		next_node = list->next;
		if (list->content)
			del(list->content);
		list->content = NULL;
		free(list);
		list = next_node;
	}
	*lst = NULL;
}
