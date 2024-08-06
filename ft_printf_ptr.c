/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:59:52 by aistok            #+#    #+#             */
/*   Updated: 2024/07/18 20:20:08 by aistok           ###   ########.fr       */
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

int	ft_printf_ptr(size_t nbr, int base, char *bdigit)
{
	int		len;
	size_t	nbr_cpy;
	t_list	*str;

	if (nbr == 0)
		return (ft_printf_str("(nil)"));
	str = NULL;
	nbr_cpy = nbr;
	len = ft_printf_count_unsigned_digits(nbr);
	while (nbr != 0)
	{
		ft_lstadd_front(&str, ft_lstnew(alloc_ch(bdigit[nbr % base])));
		nbr = nbr / base;
	}
	ft_lstadd_front(&str, ft_lstnew(alloc_ch('x')));
	ft_lstadd_front(&str, ft_lstnew(alloc_ch(bdigit[0])));
	len = ft_printf_str_list(str);
	ft_lstclear(&str, &free);
	return (len);
}
