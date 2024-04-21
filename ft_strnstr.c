/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:10:13 by aistok            #+#    #+#             */
/*   Updated: 2024/04/19 19:28:45 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

/*
 *	DESCRIPTION
 *	The strnstr() function locates the first occurrence of the null-
 *	terminated string little in the string big, where not more than len
 *	characters are searched. Characters that appear after a ‘\0’ character
 *	are not searched. Since the strnstr() function is a FreeBSD specific
 *	API, it should only be used when portability is not a concern.
 *
 *	RETURN VALUES
 *	If little is an empty string, big is returned; if little occurs nowhere
 *	in big, NULL is returned; otherwise a pointer to the first character of
 *	the first occurrence of little is returned.
 *
 *	FOR TESTING:
 *		1. little as ""
 *		2. len = 0
 *		3. 1 & 2 together
 *		4. test len = 0 to len = maxlen(little, big)
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*l;
	char	*b;
	char	*btmp;
	size_t	chars;

	if (little && *little == 0)
		return ((char *)big);
	b = (char *)big;
	while (len > 0 && *b != 0)
	{
		btmp = b;
		l = (char *)little;
		chars = len;
		while (chars-- > 0 && *l != 0)
		{
			if (*l != *btmp++)
				break ;
			l++;
			//btmp++;
			//chars--;
		}
		if (*l == 0)
			return (b);
		b++;
		len--;
	}
	return (0);
}
