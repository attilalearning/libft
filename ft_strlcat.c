/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:26:22 by aistok            #+#    #+#             */
/*   Updated: 2024/05/02 15:18:45 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>

/*
 *	dst == NULL || src == NULL not handled
 *
 *	NOTE:
 *	Should test against the original strlcat function to see if the
 *	condition in the 1st while loop is correct to be size > 0 and
 *	NOT size > 1 ????
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = 0;
	while (size > 0 && *dst != 0)
	{
		dst++;
		size--;
		len++;
	}
	while (size > 1 && *src != 0)
	{
		*dst++ = *src++;
		size--;
		len++;
		if (size == 1 || (size > 1 && *src == 0))
			*dst = 0;
	}
	while (*src != 0)
	{
		src++;
		len++;
	}
	return (len);
}
