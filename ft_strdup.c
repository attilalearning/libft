/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:22:23 by aistok            #+#    #+#             */
/*   Updated: 2024/04/23 15:15:03 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	str = (char *)s;
	while (*str++ != 0)
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (*s != 0)
		*str++ = *s++;
	*str = 0;
	while (len-- > 0)
		str--;
	return (str);
}
