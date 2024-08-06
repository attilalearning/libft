/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:55:50 by aistok            #+#    #+#             */
/*   Updated: 2024/05/09 13:39:20 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list */
#include "libft.h"

/*
 *	Description
 *	Iterates the list ’lst’ and applies the function ’f’ on the content
 *	of each node.
 *
 * 	Parameters
 * 	lst: The address of a pointer to a node.
 * 	f: The address of the function used to iterate on the list.
 *
 * 	Return value
 * 	None.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		if (lst->content)
			f(lst->content);
		lst = lst->next;
	}
}
