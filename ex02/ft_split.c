/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:29:27 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/22 21:18:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_contains_char(char c, char *charset)
{
	while (*charset && c != *charset)
		charset++;
	if (*charset)
		return (1);
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;

	n = 0;
	while (*(dest + n))
		n++;
	while (1 < size-- && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (n);
}

unsigned int	get_word_count(char *str, char *charset)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_contains_char(*str, charset))
			str++;
		if (*str)
			count++;
		while (*str && !is_contains_char(*str, charset))
			str++;
	}
	return (count);
}

char	*get_next_word(char *str, char *charset)
{
	char	*word;
	char	*_str;

	while (*str && is_contains_char(*str, charset))
		str++;
	_str = str;
	while (*str && !is_contains_char(*str, charset))
		str++;
	word = (char *)malloc((str - _str + 1) * sizeof(char));
	ft_strlcpy(word, _str, str - _str + 1);
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words_num;
	int		i;
	int		n;

	words_num = get_word_count(str, charset);
	result = (char **)malloc((words_num + 1) * sizeof(char *));
	i = 0;
	while (i < words_num)
	{
		result[i] = get_next_word(str, charset);
		n = 0;
		while (*str && is_contains_char(*str, charset))
			str++;
		while (*str && !is_contains_char(*str, charset))
			str++;
		i++;
	}
	result[i] = 0;
	return (result);
}
