/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:34:36 by aistok            #+#    #+#             */
/*   Updated: 2024/05/06 16:05:01 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>
/* used for NULL */
#include <stddef.h>

/*
 *	DESCRIPTION
 *	The  memcpy()  function  copies  n bytes from memory area src to memory
 *	area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
 *	memory areas do overlap.
 *
 *	RETURN VALUE
 *	The memcpy() function returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;

	if (!dest && !src)
		return (NULL);
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
