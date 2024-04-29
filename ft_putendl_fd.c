/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:33:22 by aistok            #+#    #+#             */
/*   Updated: 2024/04/29 13:00:25 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for write */
#include <unistd.h>
/* used for ft_putstr_fd */
#include "libft.h"

/*
 *	Description
 *	Outputs the string ’s’ to the given file descriptor followed by a newline.
 *
 *	Return value
 *	None
 */
void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	if (fd == -1)
		return ;
	ft_putstr_fd(s, fd);
	endl = '\n';
	write(fd, &endl, sizeof(char));
}
