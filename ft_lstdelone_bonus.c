/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:08:56 by aistok            #+#    #+#             */
/*   Updated: 2024/05/07 21:12:53 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list */
#include "libft.h"
/* use for free */
#include <stdlib.h>

/*
 *	Description
 *	Takes as a parameter a node and frees the memory of the node’s content
 *	using the function ’del’ given as a parameter and free the node. The
 *	memory of ’next’ must not be freed.
 *
 *	Parameters
 *	lst: The node to free.
 *	del: The address of the function used to delete the content.
 *
 *	Return value
 *	None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}
