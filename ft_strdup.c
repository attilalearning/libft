/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:22:23 by aistok            #+#    #+#             */
/*   Updated: 2024/05/11 23:13:50 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>
/* used for malloc and NULL */
#include <stdlib.h>

/*
 *	DESCRIPTION
 *	The  strdup() function returns a pointer to a new string which is a du‐
 *	plicate of the string s.  Memory for the new string  is  obtained  with
 *	malloc(3), and can be freed with free(3).
 *
 *	RETURN VALUE
 *	On  success,  the strdup() function returns a pointer to the duplicated
 *	string.  It returns NULL if insufficient memory was available, with er‐
 *	rno set to indicate the cause of the error.
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = 0;
	str = (char *)s;
	while (*str++ != 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*s != 0)
		*str++ = *s++;
	*str = 0;
	return (str - len);
}
