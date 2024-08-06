/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:55:18 by aistok            #+#    #+#             */
/*   Updated: 2024/06/05 19:19:45 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for ft_lstnew, ft_lstadd_back */
#include "libft.h"
#include "get_next_line_bonus.h"
/* used for NULL, malloc, free */
#include <stdlib.h>

void	ft_lstremove(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*n2rm;

	if (!lst || !*lst || !node || !del)
		return ;
	n2rm = *lst;
	while (n2rm && n2rm != node && n2rm->next != node)
		n2rm = n2rm->next;
	if (*lst != node && !n2rm)
		return ;
	if (*lst == node)
		*lst = (*lst)->next;
	else
		n2rm->next = n2rm->next->next;
	del(node->content);
	free(node);
}

/*
 *	If node is NULL, the whole *lst is cleared, otherwise, only the given
 *	node is cleared.
 */
void	ft_lstclear_gnl(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*fd_lst;
	t_list	*main_lst;

	main_lst = *lst;
	while (main_lst)
	{
		fd_lst = (t_list *)main_lst->content;
		if ((node && node == fd_lst) || (node == NULL))
		{
			while (fd_lst->next)
				ft_lstremove(&fd_lst, fd_lst->next, &free);
			del(fd_lst->content);
			fd_lst->content = NULL;
			ft_lstremove(lst, main_lst, &free);
			if (node && node == fd_lst)
				break ;
			main_lst = *lst;
		}
		else
			main_lst = main_lst->next;
	}
}

/*
 *	Description:
 *	Will set the info->fd_lst variable to point to the linked list associated
 *	with the given fd; if the fd was not encountered before, it will create a
 *	new linked list and point info->fd_lst to it.
 *
 *	Return value:
 *	1 (true) - if the fd was set active
 *	0 (false) - if the operation failed and currently, it can only fail if
 *	there is not enough memory to create the linked list for the requested
 *	fd (if the fd encountered is of course new to this point).
 */
int	set_active_fd(int fd, t_gnl *info)
{
	t_list	*node;
	int		*ptr_fd;

	node = info->fd_buffs;
	info->fd_lst = NULL;
	while (node && *(int *)((t_list *)node->content)->content != fd)
		node = node->next;
	if (node)
		info->fd_lst = (t_list *)node->content;
	if (!info->fd_lst && info->bytes_read > 0)
	{
		ptr_fd = malloc(sizeof(int));
		if (!ptr_fd)
			return (0);
		*ptr_fd = fd;
		info->fd_lst = ft_lstnew(ptr_fd);
		node = ft_lstnew(info->fd_lst);
		ft_lstadd_back(&info->fd_buffs, node);
	}
	return (1);
}
