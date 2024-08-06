/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:03 by aistok            #+#    #+#             */
/*   Updated: 2024/05/09 18:19:32 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list */
#include "libft.h"
/* used for malloc and NULL */
#include <stdlib.h>

/*
 *	Description
 *	Allocates (with malloc(3)) and returns a new node. The member variable
 *	’content’ is initialized with the value of the parameter ’content’. The
 *	variable ’next’ is initialized to NULL.
 *
 *	Return value
 *	The new node.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
