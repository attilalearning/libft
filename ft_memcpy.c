/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:34:36 by aistok            #+#    #+#             */
/*   Updated: 2024/04/17 18:41:26 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	while (n > 0)
	{
		*c_dest = *c_src;
		c_dest++;
		c_src++;
		n--;
	}
	return (dest);
}
