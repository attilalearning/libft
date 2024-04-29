/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:34:33 by aistok            #+#    #+#             */
/*   Updated: 2024/04/27 21:03:02 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for malloc */
#include <stdlib.h>
/* used for NULL */
#include <aio.h>

int	count_digits(int n)
{
	int	len;

	len = 1 + (n < 0);
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*
 *	Description
 *	Allocates (with malloc(3)) and returns a string representing the integer
 *	received as an argument. Negative numbers must be handled.
 *
 *	Return value
 *	The string representing the integer.
 *	NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[len] = 0;
	while (n != 0)
	{
		if (n < 0)
			str[--len] = (n % 10) * (-1) + 48;
		else
			str[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
