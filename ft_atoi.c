/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:49:32 by aistok            #+#    #+#             */
/*   Updated: 2024/05/09 14:48:12 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

/*
 *	DESCRIPTION
 *	The  atoi() function converts the initial portion of the string pointed
 *	to by nptr to int. The behavior is the same as
 *		strtol(nptr, NULL, 10);
 *	except that atoi() does not detect errors.
 *
 *	RETURN VALUE
 *	The converted value or 0 on error.
 *
 *	FOR TESTING:
 *		 1. INT_MIN
 *		 2. INT_MIN - 1
 *		 3. INT_MAX
 *		 4. INT_MAX + 1
 *		 5. spaces followed by number
 *		 6. spaces ++ sign number
 *		 7. spaces -- ...
 *		 8. spaces +- ...
 *		 9. spaces + sign number
 *		10. spaces - sign number
 *		11. spaces number letter number
 *		12. spaces - ...
 *		13. spaces + ...
 *		14. repeat 5 - 13 without spaces
 */
int	ft_atoi(const char *nptr)
{
	char	sign;
	int		number;

	sign = 1;
	number = 0;
	while (*nptr != 0 && ft_isspace(*nptr))
		nptr++;
	if (*nptr != 0 && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = sign * (-1);
		nptr++;
	}
	while (*nptr != 0 && ft_isdigit(*nptr))
	{
		number = number * 10 + (*nptr - '0');
		nptr++;
	}
	return (number * sign);
}
