/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:37:49 by aistok            #+#    #+#             */
/*   Updated: 2024/05/11 22:54:34 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for ft_strchr, ft_strdup, ft_calloc, ft_memcpy */
#include "libft.h"
/* used for size_t */
#include <aio.h>
/* used for NULL */
#include <stddef.h>

/*
 *	Description
 *	Allocates (with malloc(3)) and returns a copy of ’s1’ with the
 *	characters specified in ’set’ removed from the beginning and the end
 *	of the string.
 *
 *	Return value
 *	The trimmed string.
 *	NULL if the allocation fails.
 *
 *	NOTE:
 *	I used calloc, because it will bzero the mem area and I do not have to add
 *	a terminating zero to the result! :)
 *	!!! For better performance, CONSIDER USING ft_strcpy instead of calloc,
 *	which may take some time to ZERO the memory area?
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start;
	char	*end;
	size_t	len;

	if (!s1)
		return (NULL);
	start = (char *)s1;
	while (set != NULL && *start != 0 && ft_strchr(set, *start) != 0)
		start++;
	if (*start == 0)
		return (ft_strdup(""));
	end = (char *)s1;
	while (*end != 0)
		end++;
	if (end > start)
		end--;
	while (set != NULL && end > start && ft_strchr(set, *end) != 0)
		end--;
	len = end - start + 1;
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	result = ft_memcpy(result, start, len);
	return (result);
}
