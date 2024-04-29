/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:07:53 by aistok            #+#    #+#             */
/*   Updated: 2024/04/29 11:16:59 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for write */
#include <unistd.h>

/*
 *	Description
 *	Outputs the character ’c’ to the given file descriptor.
 *
 *	Return value
 *	None
 */
void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, sizeof(char));
}
