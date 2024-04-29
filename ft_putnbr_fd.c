/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:02:44 by aistok            #+#    #+#             */
/*   Updated: 2024/04/29 13:15:57 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for write */
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd == -1)
		return ;
	if (n / 10 == 0)
	{
		if (n < 0)
		{
			n = n * (-1);
			write(fd, "-", sizeof(char));
		}
		c = (n % 10) + 48;
		write(fd, &c, sizeof(char));
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
			c = (n % 10) * (-1) + 48;
		else
			c = n % 10 + 48;
		write(fd, &c, sizeof(char));
	}
}
