/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:01:29 by aistok            #+#    #+#             */
/*   Updated: 2024/05/09 17:33:58 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list */
#include "libft.h"
/* used for NULL */
#include <stddef.h>

/*
 *	Description
 *	Adds the node ’new’ at the end of the list.
 *
 *	Return value
 *	None.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	while (last && last->next)
		last = last->next;
	if (!last)
		*lst = new;
	else
		last->next = new;
}
