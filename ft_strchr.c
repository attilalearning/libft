/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:16:38 by aistok            #+#    #+#             */
/*   Updated: 2024/04/29 14:00:14 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for NULL */
#include <stddef.h>

/*
 *	DESCRIPTION
 *	The  strchr() function returns a pointer to the first occurrence of the
 *	character c in the string s.
 *
 *	RETURN VALUE
 *	The strchr() and strrchr() functions return a pointer  to  the  matched
 *	character  or NULL if the character is not found.  The terminating null
 *	byte is considered part of the string, so that if  c  is  specified  as
 *	'\0', these functions return a pointer to the terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
