/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:16:38 by aistok            #+#    #+#             */
/*   Updated: 2024/04/18 19:21:34 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*beginning;

	beginning = (char *)s;
	while (*s != 0)
		s++;
	while (s != beginning)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
