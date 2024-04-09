/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:34:36 by aistok            #+#    #+#             */
/*   Updated: 2024/04/09 15:29:11 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_saved;

	dest_saved = dest;
	while (n > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest_saved);
}
