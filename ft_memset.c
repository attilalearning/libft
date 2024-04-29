/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:31:18 by aistok            #+#    #+#             */
/*   Updated: 2024/04/17 18:42:06 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>

void	ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	if (!s)
		return ;
	src = (unsigned char *)s;
	while (n > 0)
	{
		*src = (unsigned char)c;
		src++;
		n--;
	}
}
