/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:00:01 by aistok            #+#    #+#             */
/*   Updated: 2024/04/30 00:26:32 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for ft_strlen */
#include "libft.h"
/* used for malloc */
#include <stdlib.h>
/* used for size_t */
#include <aio.h>
/* used for errno & ENOMEM */
#include <errno.h>
/* used for NULL */
#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1);
	len += ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (*s1 != 0)
		*result++ = *s1++;
	while (*s2 != 0)
		*result++ = *s2++;
	*result = 0;
	while (len-- > 0)
		result--;
	return (result);
}
