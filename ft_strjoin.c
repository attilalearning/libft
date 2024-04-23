/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:00:01 by aistok            #+#    #+#             */
/*   Updated: 2024/04/23 19:17:21 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <aio.h>
#include <errno.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_tmp;
	char	*result;
	size_t	len;

	len = 0;
	s_tmp = (char *)s1;
	while (*s_tmp++ != 0)
		len++;
	s_tmp = (char *)s2;
	while (*s_tmp++ != 0)
		len++;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
	{
		errno = ENOMEM;
		return (0);
	}
	while (*s1 != 0)
		*result++ = *s1++;
	while (*s2 != 0)
		*result++ = *s2++;
	*result = 0;
	while (len-- > 0)
		result--;
	return (result);
}
