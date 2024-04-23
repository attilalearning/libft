/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:57:59 by aistok            #+#    #+#             */
/*   Updated: 2024/04/23 14:19:24 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

/*
 *	DESCRIPTION
 *	The calloc() function allocates memory for an array of  nmemb  elements
 *	of size bytes each and returns a pointer to the allocated memory. The
 *	memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
 *	either  NULL,  or a unique pointer value that can later be successfully
 *	passed to free().  If the multiplication of nmemb and size would result
 *	in  integer  overflow, then calloc() returns an error.
 *
 *	RETURN VALUE
 *	The calloc() function returns a pointer to the allocated memory, which
 *	is  suitably  aligned for any built-in type.  On error, calloc() returns
 *	NULL. NULL may also be returned by a successful call to calloc() with
 *	nmemb or size equal to zero.
 *
 *	NOTE:
 *	The overflow test can also be done as below, however, this version
 *	may still not catch all cases of overflow, since the total_size can
 *	be a number that got overflown already?!
 *	if (nmemb && size && (total_size / nmemb != size))
 *
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr_to_mem_area;

	if (nmemb && (SIZE_MAX / nmemb < size))
	{
		errno = ENOMEM;
		return (0);
	}
	total_size = nmemb * size;
	ptr_to_mem_area = malloc(total_size);
	if (!ptr_to_mem_area)
		return (0);
	else
		ft_bzero(ptr_to_mem_area, total_size);
	return (ptr_to_mem_area);
}
