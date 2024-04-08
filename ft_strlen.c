/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:38:42 by aistok            #+#    #+#             */
/*   Updated: 2024/04/08 19:06:54 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;
	char	*ptr;

	len = 0;
	ptr = &s;
	while (*ptr != 0)
	{
		len++;
		ptr++;
	}
	return (len);
}
