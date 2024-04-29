/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:16:42 by aistok            #+#    #+#             */
/*   Updated: 2024/04/17 18:40:16 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;

	if (!s || !n)
		return ;
	src = s;
	while (n > 0)
	{
		*src = 0;
		src++;
		n--;
	}
}
