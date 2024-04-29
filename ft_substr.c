/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:17:54 by aistok            #+#    #+#             */
/*   Updated: 2024/04/23 16:12:52 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <aio.h>
#include <errno.h>
/* used for NULL */
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*result;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	result = str;
	while (len > 0 && *s != 0 && start-- > 0)
		s++;
	while (len > 0 && *s != 0)
	{
		*str++ = *s++;
		len--;
	}
	*str = 0;
	return (result);
}
