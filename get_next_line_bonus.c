/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:53:52 by aistok            #+#    #+#             */
/*   Updated: 2024/06/10 19:19:35 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for the ft_lst* functions */
#include "get_next_line_bonus.h"
/* used for read */
#include <unistd.h>
/* used for NULL */
#include <aio.h>
/* used for malloc, free */
#include <stdlib.h>

char	*get_next_line(int fd);
int		merge_has_nl_or_eof(t_gnl *info);
int		copy_buf_2_lst(t_gnl *info);
char	*get_one_line(t_gnl *info);
char	*make_line_str(t_gnl *info, size_t len);

char	*get_next_line(int fd)
{
	static t_gnl	info = {.bytes_read = 0, .fd_lst = NULL, \
				.fd_buffs = NULL, .buf = NULL };

	if (fd <= -1 || BUFFER_SIZE == 0)
		return (NULL);
	info.buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!info.buf)
		return (NULL);
	info.bytes_read = read(fd, info.buf, BUFFER_SIZE);
	if (info.bytes_read == -1 || !set_active_fd(fd, &info))
	{
		if (info.bytes_read > -1)
			ft_lstclear_gnl(&info.fd_buffs, info.fd_lst, &free);
		free(info.buf);
		return (NULL);
	}
	while (!merge_has_nl_or_eof(&info))
		info.bytes_read = read(fd, info.buf, BUFFER_SIZE);
	free(info.buf);
	return (get_one_line(&info));
}

/*
 * 	Description:
 *	Will copy content of buf into data and will check if data has at least
 *	one '\n' present, or if the last read reached the EOF.
 *
 *	Return value
 *	1 (or true), if at least one '\n' is found in data (after copying buf
 *	into it) or if EOF was reached.
 *	0 (or false), if EOF was not reached and if no '\n' is found in
 *	data (after the merge).
 */
int	merge_has_nl_or_eof(t_gnl *info)
{
	t_list	*data;

	copy_buf_2_lst(info);
	if (!info->fd_lst)
		return (1);
	data = info->fd_lst->next;
	while (data && *(char *)(data->content) != '\n')
		data = data->next;
	if (data && *(char *)(data->content) == '\n')
		return (1);
	if (!data && info->bytes_read == 0)
		return (1);
	return (0);
}

int	copy_buf_2_lst(t_gnl *info)
{
	ssize_t	i;
	char	*ch;

	i = 0;
	while (i < info->bytes_read)
	{
		ch = malloc(sizeof(char));
		if (!ch)
		{
			ft_lstclear_gnl(&info->fd_buffs, info->fd_lst, &free);
			info->fd_lst = NULL;
			return (0);
		}
		*ch = info->buf[i++];
		ft_lstadd_back(&info->fd_lst, ft_lstnew(ch));
	}
	return (1);
}

char	*get_one_line(t_gnl *info)
{
	t_list	*tmp;
	size_t	len;

	if (!info->fd_lst || !info->fd_lst->next)
		return (NULL);
	len = 0;
	tmp = info->fd_lst->next;
	while (tmp && *(char *)(tmp->content) != '\n')
	{
		len = len + 1;
		tmp = tmp->next;
	}
	if (tmp && *(char *)(tmp->content) == '\n')
		len++;
	return (make_line_str(info, len));
}

char	*make_line_str(t_gnl *info, size_t len)
{
	char	*line;
	size_t	count;
	t_list	*node_2_remove;
	t_list	*tmp;

	line = malloc(sizeof(char) * (len + 1));
	if (line)
	{
		tmp = info->fd_lst->next;
		count = len;
		while (count--)
		{
			node_2_remove = tmp;
			*line = *(char *)(tmp->content);
			line++;
			tmp = tmp->next;
			ft_lstremove(&info->fd_lst, node_2_remove, &free);
		}
		*line = '\0';
	}
	if (!info->fd_lst->next)
		ft_lstclear_gnl(&info->fd_buffs, info->fd_lst, &free);
	return (line - len);
}
