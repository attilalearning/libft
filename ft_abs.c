/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:37:01 by aistok            #+#    #+#             */
/*   Updated: 2025/01/17 14:59:38 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// !!! INT_MIN & INT_MAX ???
int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}
