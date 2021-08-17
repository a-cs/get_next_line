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

size_t	ft_strlen(const char *s)
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

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		pos;

	cpy = (char *)malloc(ft_strlen(s1) + 1);
	pos = 0;
	while (s1[pos])
	{
		cpy[pos] = s1[pos];
		pos++;
	}
	cpy[pos] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	while (s1[pos1] != '\0')
	{
		str[pos1] = s1[pos1];
		pos1++;
	}
	while (s2[pos2] != '\0')
	{
		str[pos1 + pos2] = s2[pos2];
		pos2++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	char_c;

	str = (unsigned char *) s;
	char_c = (unsigned char) c;
	while (*str != '\0')
	{
		if (*str == char_c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (char_c == '\0')
		return ((char *)str);
	return (NULL);
}
