/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:32:50 by aistok            #+#    #+#             */
/*   Updated: 2024/04/17 21:51:02 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;
	const char	*source;

	len = 0;
	source = src;
	while (*source++ != 0)
		len++;
	source = src;
	if (size > 0)
	{
		while (size > 1 && *source != 0)
		{
			*dst = *source;
			dst++;
			source++;
			size--;
		}
		*dst = 0;
	}
	return (len);
}
