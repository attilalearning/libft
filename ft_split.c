/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:03:45 by aistok            #+#    #+#             */
/*   Updated: 2024/05/06 17:22:06 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for malloc and free */
#include <stdlib.h>
/* used for NULL pointer */
#include <stddef.h>
/* used for size_t type */
#include <aio.h>

static size_t	wordlen_and_move_str_pointer(char **str, char c)
{
	size_t	len;
	char	*s;

	len = 0;
	s = *str;
	while (*s != 0 && *s != c)
	{
		s++;
		len++;
	}
	*str = s;
	return (len);
}

/*
 *	THIS FUNCTION WILL RETURN THE 1ST WORD
 *	AND !!
 *	WILL ALSO MOVE THE *str POINTER TO POINT TO JUST RIGHT AFTER THE WORD
 *	THAT IS BEING EXTRACTED (SO, TO THE NEXT SEPARATOR OR THE '\0', THE END OF
 *	STRING! :)
 *
 *	NOTE:
 *	For *str = ",,,a," and c = ',' this function will skip all the separators
 *	at the beginning and will start extracting anything starting with the 'a'.
 */
static char	*extract_first_word(char **str, char c)
{
	size_t	len;
	char	*ptr_word_begins;
	char	*word;
	char	*s;

	len = 0;
	s = *str;
	while (*s != 0 && *s == c)
		s++;
	if (*s == 0)
		return (NULL);
	ptr_word_begins = s;
	len = wordlen_and_move_str_pointer(&s, c);
	*str = s;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (ptr_word_begins != s)
		*word++ = *ptr_word_begins++;
	*word = 0;
	word = word - len;
	return (word);
}

static size_t	count_words(char *str, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*str != 0)
	{
		while (*str != 0 && *str == c)
			str++;
		if (*str == 0)
			break ;
		word_count++;
		while (*str != 0 && *str != c)
			str++;
	}
	return (word_count);
}

/*
 *	Description
 *	Allocates (with malloc(3)) and returns an array of strings obtained by
 *	splitting ’s’ using the character ’c’ as a delimiter. The array must end
 *	with a NULL pointer.
 *
 *	Return value
 *	The array of new strings resulting from the split.
 *	NULL if the allocation fails.
 *
 *	NOTE:
 *	After i++; it might make a little sense to check if i is not greater than
 *	count_words(str, c) (not to cause segmentation fault).
 *	!!! Handled the case when s IS NULL, however, had to remove the check of
 *		if (word == NULL && errno == ENOMEM)
 *			free_array(&arr, &i);
 *		because of norminette (FUNCTION WILL BE 25+ LINES)
 *		NOTE: previous commit had the free_array included and had the s IS NULL
 *		check excluded.
 */
char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*word;
	char	**arr;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	word = extract_first_word(&str, c);
	while (word)
	{
		arr[i++] = word;
		word = extract_first_word(&str, c);
	}
	arr[i] = NULL;
	return (arr);
}
