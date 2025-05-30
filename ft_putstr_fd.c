/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:02 by aistok            #+#    #+#             */
/*   Updated: 2024/04/29 12:13:38 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for write */
#include <unistd.h>
/* used for size_t */
#include <aio.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (fd == -1 || !s)
		return ;
	len = 0;
	while (*s++ != 0)
		len++;
	s = s - len - 1;
	write(fd, s, len);
}
