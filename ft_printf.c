/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:59:52 by aistok            #+#    #+#             */
/*   Updated: 2024/07/18 20:39:49 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for va_start, va_arg, va_copy, va_end */
#include <stdarg.h>
/* used for size_t */
#include <aio.h>
/* used for write */
#include <unistd.h>
/* used for malloc & free */
#include <stdlib.h>
/* used for ft_ functions */
#include "libft.h"
/* used for ft_printf_* functions */
#include "ft_printf.h"

static int	handle(va_list ap, char cv_specifier)
{
	if (cv_specifier == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (cv_specifier == 'c')
		return (ft_printf_char((char)va_arg(ap, int)));
	else if (cv_specifier == '%')
		return (ft_printf_char('%'));
	else if (cv_specifier == 'p')
		return (ft_printf_ptr(va_arg(ap, size_t), 16, "0123456789abcdef"));
	else if (cv_specifier == 'd' || cv_specifier == 'i')
		return (ft_printf_nbr(va_arg(ap, int), 10, "0123456789"));
	else if (cv_specifier == 'u')
		return (ft_printf_nbr(va_arg(ap, unsigned int), 10, "0123456789"));
	else if (cv_specifier == 'x')
		return (ft_printf_hex(\
			(unsigned int)va_arg(ap, unsigned int), 16, "0123456789abcdef"));
	else if (cv_specifier == 'X')
		return (ft_printf_hex(\
			(unsigned int)va_arg(ap, unsigned int), 16, "0123456789ABCDEF"));
	else
		return (-cv_specifier);
}

/*
 *	Description
 *	ft_printf(), a function that will mimic the original printf().
 */
int	ft_printf(const char *data, ...)
{
	va_list	ap;
	int		written;
	int		result;

	written = 0;
	va_start(ap, data);
	while (*data != 0)
	{
		if (*data == '%')
		{
			data++;
			result = handle(ap, *data);
			written += result;
			if (result < 0)
			{
				written = result;
				break ;
			}
		}
		else
			write(1, data, (++written > 0));
		data++;
	}
	va_end(ap);
	return (written);
}
