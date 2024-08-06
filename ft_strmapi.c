/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:11:11 by aistok            #+#    #+#             */
/*   Updated: 2024/04/28 16:54:50 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for NULL */
#include <stddef.h>
/* used for malloc */
#include <stdlib.h>

/*
 *	Description
 *	Applies the function f to each character of the string s, passing its index
 *	as the first argument and the character itself as the second. A new string
 *	is created (using malloc(3)) to collect the results from the successive
 *	applications of f.
 *
 *	Return value
 *	The string created from the successive applications of ’f’.
 *	Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	len = 0;
	i = 0;
	while (s[i++] != 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = 0;
	return (str);
}
