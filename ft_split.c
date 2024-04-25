/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistok <aistok@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:03:45 by aistok            #+#    #+#             */
/*   Updated: 2024/04/25 19:05:42 by aistok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* used for malloc and free */
#include <stdlib.h>

/* used for NULL pointer */
#include <stddef.h>

/* used for size_t type */
#include <aio.h>




// REMOVE BEFORE PUSHING TO GIT !!!
//getchar()
//#include <stdio.h>





/*
 *	THIS FUNCTION WILL RETURN THE 1ST WORD
 *	AND !!
 *	WILL ALSO MOVE THE *str POINTER TO POINT TO JUST RIGHT AFTER THE WORD
 *	THAT IS BEING EXTRACTED (SO, THE NEXT SEPARATOR OR THE '\0' END OF
 *	STRING! :)
 */
char	*extract_first_word(char **str, char c)
{
	size_t	len;
	char	*ptr_word_begins;
	char	*word;
	char	*s;

	len = 0;
	s = *str;
	if (*s != 0 && *s == c) //while
		s++;
	ptr_word_begins = s;
	while (*s != 0 && *s != c)
	{
		s++;
		len++;
	}
	*str = s;
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	while (ptr_word_begins != s)
		*word++ = *ptr_word_begins++;
	*word = 0;
	while (len-- > 0)
		word--;
	//printf("Returning extracted word: \"%s\"\n", word);
	return (word);
}

size_t	count_words(char *str, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*str != 0)
	{
		if (*str != 0 && *str == c)
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
 *	For ",,," this function will return [ "", "", NULL ], NULL signaling the
 *	end of the array. If this function is compared with strtkn from string.h,
 *	strtkn(",,,", ",") would return NULL !!
 */
char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	*word;
	char	**arr;
	char	*str;

	str = (char *)s;
	//printf("Counting words...\n");
	word_count = count_words((char *)s, c);
	//printf("word count = %zu\n", word_count);
	arr = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!arr)
		return (NULL);
	i = 0;
	if (!(*str == 0 || (*str == c && *(str + 1) == 0)))
		while (*str != 0)
		{
			if (!(*str == c && *(str + 1) == 0))
			{
				word = extract_first_word(&str, c);
				//printf("arr[%zu] = \"%s\"\n", i, word);
				arr[i] = word; //if word == NULL ????
				i++;
			}
			else
				str++;
			//printf("Press any key to continue...\n");
			//getchar();
		}
	arr[i] = NULL;
	//printf("arr[%zu] = \"%s\"\n", i, (char *)NULL);
	return (arr);
}
