/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:36:31 by acarneir          #+#    #+#             */
/*   Updated: 2021/08/16 22:36:31 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*str;
	char	*temp;
	ssize_t	size;

	if(str != NULL && ft_strchr(str, '\n'))
		{
			free(str);
			str = NULL;
		}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = calloc((BUFFER_SIZE + 1),1);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = '\0';
		if(!str)
			str = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str, buffer);
			free(str);
			str = temp;
		}
		if(ft_strchr(str, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (size == -1)
		return (NULL);
	if (str == NULL && size == 0)
		return (NULL);
	return (str);
}
