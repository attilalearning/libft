/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 06:00:01 by aistok            #+#    #+#             */
/*   Updated: 2025/01/18 20:24:20 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

/*
 *	THIS FUNCTION IS CALLED BY ft_atod, AND!
 *	THE nbr_dec HAS TO START WITH A DIGIT.
 *	OTHERWISE, IT WILL IGNORE ANYTHING FROM
 *	THE nbr_dec STRING!
 */
static double	ft_atod_decimal_part(char *nbr_dec)
{
	double	result;
	int		i;

	i = 0;
	if (ft_isdigit(nbr_dec[i]))
		result = nbr_dec[i++] - '0';
	else
		result = 0.0;
	while (nbr_dec[i] && ft_isdigit(nbr_dec[i]))
		result = result * 10 + (nbr_dec[i++] - '0');
	if (result > 0)
		while (i--)
			result = result / 10;
	return (result);
}

static void	set_minus_one(int *i)
{
	*i = -1;
}

/*
 *	TESTED, WORKS WELL IN MOST CASES.
 *	-+0.0 will return -0.0, whereas atof will return 0.0
 *	and for 1.178921 it will return 1.178920999... whereas atof will return
 *	1.178921
 *
 *	similar small differences might arise...
 */
double	ft_atod(char *nbr)
{
	double	result;
	int		i;
	int		sign;

	result = 0.0;
	i = 0;
	sign = 1;
	while (nbr[i] && ft_isspace(nbr[i]))
		i++;
	if (nbr[i] && nbr[i] == '-')
		(set_minus_one(&sign), i++);
	else if (nbr[i] && nbr[i] == '+')
		i++;
	while (nbr[i] && ft_isdigit(nbr[i]) && nbr[i] == '0')
		i++;
	if (nbr[i] && ft_isdigit(nbr[i]))
		result += nbr[i++] - '0';
	while (nbr[i] && ft_isdigit(nbr[i]))
		result = result * 10 + (nbr[i++] - '0');
	if (nbr[i] && nbr[i] == '.')
		i++;
	if (nbr[i] && ft_isdigit(nbr[i]))
		result += ft_atod_decimal_part(&nbr[i]);
	return (result * sign);
}
