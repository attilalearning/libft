/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:00:33 by aistok            #+#    #+#             */
/*   Updated: 2024/07/18 19:13:04 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <aio.h>
# include "libft.h"

int		ft_printf(const char *data, ...);
int		ft_printf_char(const char ch);
int		ft_printf_str(const char *str);
int		ft_printf_nbr(ssize_t nbr, int base, char *bdigit);
int		ft_printf_hex(unsigned int nbr, int base, char *bdigit);
int		ft_printf_ptr(size_t nbr, int base, char *bdigit);

/* ft_printf utils functions */
int		ft_printf_count_signed_digits(ssize_t n);
int		ft_printf_count_unsigned_digits(size_t n);
char	*alloc_ch(char c);
int		ft_printf_str_list(t_list *str);

#endif
