/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:31:18 by aistok            #+#    #+#             */
/*   Updated: 2024/04/30 00:42:01 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>
/* used for NULL */
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	if (!s)
		return (NULL);
	src = (unsigned char *)s;
	while (n > 0)
	{
		*src = (unsigned char)c;
		src++;
		n--;
	}
	return (s);
}
