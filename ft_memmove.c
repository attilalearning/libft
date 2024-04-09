/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:18 by aistok            #+#    #+#             */
/*   Updated: 2024/04/09 19:29:26 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 *	NEEDS TESTING !!!!!
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*d;
	
	d = dest;
	if (dest <= src)
	{
		while (n > 0)
		{
			*(char *)dest = *(char *)src;
			n--;
			dest++;
			src++;
		}
	}
	else
	{
		dest = dest + n;
		src = src + n;
		while (n > 0)
		{
			dest--;
			src--;
			*(char *)dest = *(char *)src;
			n--;
		}
	}
	return (d);
}
