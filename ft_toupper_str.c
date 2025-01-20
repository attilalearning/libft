/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:00:00 by aistok            #+#    #+#             */
/*   Updated: 2025/01/18 19:46:48 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

char	*ft_toupper_str(char *str)
{
	char	*capital_str;
	int		i;

	if (!str)
		return (NULL);
	capital_str = ft_strdup(str);
	i = 0;
	while (capital_str[i])
	{
		capital_str[i] = ft_toupper(capital_str[i]);
		i++;
	}
	return (capital_str);
}
