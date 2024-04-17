/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:18 by aistok            #+#    #+#             */
/*   Updated: 2024/04/17 18:41:11 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	
	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (c_dest <= c_src)
	{
		while (n > 0)
		{
			*c_dest = *c_src;
			n--;
			c_dest++;
			c_src++;
		}
	}
	else
	{
		c_dest = c_dest + n;
		c_src = c_src + n;
		while (n > 0)
		{
			c_dest--;
			c_src--;
			*c_dest = *c_src;
			n--;
		}
	}
	return (dest);
}
