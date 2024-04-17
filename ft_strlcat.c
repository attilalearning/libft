/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:26:22 by aistok            #+#    #+#             */
/*   Updated: 2024/04/17 21:45:01 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	const char	*source;

	len = 0;
	source = src;
	while (size > 0 && *dst != 0)
	{
		dst++;
		size--;
		len++;
	}
	while (size > 1 && *source != 0)
	{
		*dst++ = *source++;
		size--;
		len++;
		if (*source == 0)
			*dst = 0;
	}
	while (*source != 0)
	{
		source++;
		len++;
	}
	return (len);
}
