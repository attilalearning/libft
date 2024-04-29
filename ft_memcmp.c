/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:14:37 by aistok            #+#    #+#             */
/*   Updated: 2024/04/19 16:02:38 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*zone1;
	unsigned char	*zone2;

	zone1 = (unsigned char *)s1;
	zone2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*zone1 != *zone2)
			return (*zone1 - *zone2);
		zone1++;
		zone2++;
		n--;
	}
	if (n > 0)
		return (*zone1 - *zone2);
	return (0);
}
