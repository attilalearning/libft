/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:10:06 by aistok            #+#    #+#             */
/*   Updated: 2024/04/28 20:07:41 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Description
 *	Applies the function ’f’ on each character of the string passed as
 *	argument, passing its index as first argument. Each character is passed by
 *	address to ’f’ to be modified if necessary.
 *
 *	Return value
 *	None.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (*s != 0)
		f(i++, s++);
}
