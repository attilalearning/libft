/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:43:08 by aistok            #+#    #+#             */
/*   Updated: 2024/05/07 18:50:11 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for t_list */
#include "libft.h"

/*
 *	Description
 *	Counts the number of nodes in a list.
 *
 *	Return value
 *	The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
