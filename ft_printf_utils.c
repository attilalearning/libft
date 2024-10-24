/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:59:52 by aistok            #+#    #+#             */
/*   Updated: 2024/07/18 20:28:34 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t & ssize_t */
#include <aio.h>
/* used for write */
#include <unistd.h>
/* used for malloc & free */
#include <stdlib.h>
/* used for ft_ functions */
#include "libft.h"

int	ft_printf_count_signed_digits(ssize_t n)
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

int	ft_printf_count_unsigned_digits(size_t n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*alloc_ch(char c)
{
	char	*ch_ptr;

	ch_ptr = (char *)malloc(sizeof(char));
	if (ch_ptr)
		*ch_ptr = c;
	return (ch_ptr);
}

int	ft_printf_str_list(t_list *str)
{
	int	written;

	written = 0;
	while (str)
	{
		write(1, (char *)(str->content), 1);
		str = str->next;
		written++;
	}
	return (written);
}
