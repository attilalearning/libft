/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:59:52 by aistok            #+#    #+#             */
/*   Updated: 2024/05/18 02:34:01 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for write */
#include <unistd.h>
/* used for ft_printf_str */
#include "ft_printf.h"

int	ft_printf_str(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_printf_str("(null)"));
	while (*str != 0)
	{
		write(1, str, 1);
		len++;
		str++;
	}
	return (len);
}
