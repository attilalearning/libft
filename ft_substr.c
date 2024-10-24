/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:17:54 by aistok            #+#    #+#             */
/*   Updated: 2024/05/02 21:35:08 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for malloc */
#include <stdlib.h>
/* used for size_t */
#include <aio.h>
/* used for NULL */
#include <stddef.h>
/* used for ft_strlen & ft_strdup */
#include "libft.h"

/*
 *	If slen = 0 it means, we have an empty string (terminated by '\0'), hence
 *	slen <= start is OK!
 *
 *	NOTE: start goes from 0 to string len - 1
 *
 *	NOTE: the 2nd while loop can be shortened from 5 lines to only 2:
 *	while (len-- > 0 && *s != 0)
 *		*str++ = *s++;
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*result;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	else
		if (len > slen - start)
			len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
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
