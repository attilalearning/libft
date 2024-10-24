/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:59:52 by aistok            #+#    #+#             */
/*   Updated: 2024/07/18 20:19:50 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for size_t */
#include <aio.h>
/* used for malloc & free */
#include <stdlib.h>
/* used for ft_ functions: ft_lst* */
#include "libft.h"
/* used for ft_printf_str_list and the ft_printf utils functions */
#include "ft_printf.h"

int	ft_printf_hex(unsigned int nbr, int base, char *bdigit)
{
	int		len;
	t_list	*str;

	str = NULL;
	len = ft_printf_count_unsigned_digits(nbr);
	if (nbr == 0)
		str = ft_lstnew(alloc_ch('0'));
	while (nbr != 0)
	{
		ft_lstadd_front(&str, ft_lstnew(alloc_ch(bdigit[nbr % base])));
		nbr = nbr / base;
	}
	len = ft_printf_str_list(str);
	ft_lstclear(&str, &free);
	return (len);
}
