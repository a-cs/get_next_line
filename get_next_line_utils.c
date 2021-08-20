/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 23:33:57 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/16 23:33:57 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		pos;

	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy)
		return (NULL);
	pos = 0;
	while (s1[pos])
	{
		cpy[pos] = s1[pos];
		pos++;
	}
	cpy[pos] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		pos1;
	int		pos2;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	pos1 = 0;
	pos2 = 0;
	while (s1 != NULL && s1[pos1] != '\0')
	{
		str[pos1] = s1[pos1];
		pos1++;
	}
	while (s1 != NULL && s2[pos2] != '\0')
	{
		str[pos1 + pos2] = s2[pos2];
		pos2++;
	}
	str[pos1 + pos2] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	char_c;

	str = s;
	char_c = (char) c;
	while (*str != '\0')
	{
		if (*str == char_c)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	count;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	count = 0;
	while (count < len)
	{
		substr[count] = s[start + count];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	char	find_c;

// 	find_c = c;
// 	while (*s != find_c)
// 	{
// 		if (*s == '\0')
// 			return (NULL);
// 		s++;
// 	}
// 	return ((char *)s);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new_string;
// 	char	*hold_pointer;
// 	size_t	s1_len;
// 	size_t	s2_len;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1_len = 0;
// 	s2_len = 0;
// 	while (s1[s1_len])
// 		s1_len++;
// 	while (s2[s2_len])
// 		s2_len++;
// 	new_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
// 	if (!new_string)
// 		return (NULL);
// 	hold_pointer = new_string;
// 	while (*s1)
// 		*new_string++ = *s1++;
// 	while (*s2)
// 		*new_string++ = *s2++;
// 	*new_string = '\0';
// 	return (hold_pointer);
// }

// char	*ft_strdup(const char *str)
// {
// 	char	*ptr;
// 	size_t	size;

// 	size = 0;
// 	while (str[size])
// 		size++;
// 	size++;
// 	ptr = (char *) malloc(size * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, str, size);
// 	return ((char *) ptr);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	x;
// 	size_t	counter;

// 	x = 0;
// 	if (!dst || !src)
// 		return (0);
// 	if (dstsize)
// 	{
// 		while (src[x] && x < (dstsize - 1))
// 		{
// 			dst[x] = src[x];
// 			x++;
// 		}
// 		dst[x] = '\0';
// 	}
// 	counter = 0;
// 	while (src[counter])
// 		counter++;
// 	return (counter);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*substring_ptr;
// 	size_t			str_len;

// 	if (!s)
// 		return (NULL);
// 	str_len = 0;
// 	while (s[str_len])
// 		str_len++;
// 	if (start > str_len)
// 		return (ft_strdup(""));
// 	else if (start + len > str_len)
// 		len = str_len - start;
// 	substring_ptr = malloc((len + 1) * sizeof(char));
// 	if (!substring_ptr)
// 		return (NULL);
// 	ft_strlcpy (substring_ptr, s + start, len + 1);
// 	return (substring_ptr);
// }