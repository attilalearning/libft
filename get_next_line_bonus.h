/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:50:14 by aistok            #+#    #+#             */
/*   Updated: 2024/06/06 19:14:28 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <aio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	ssize_t	bytes_read;
	char	*buf;
	t_list	*fd_lst;
	t_list	*fd_buffs;
}		t_gnl;

char	*get_next_line(int fd);

void	ft_lstremove(t_list **lst, t_list *node, void (*del)(void *));
void	ft_lstclear_gnl(t_list **lst, t_list *node, void (*del)(void *));
int		set_active_fd(int fd, t_gnl *info);

#endif
