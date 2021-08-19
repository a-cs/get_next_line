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

char *get_next_line(int fd)
{
	char *buffer;
	static char *str;
	char *temp;
	char *new_temp;
	char *line;
	ssize_t size;
	int		pos;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		ft_free(buffer);
		return (NULL);
	}
	if (!str)
		str = ft_strdup(buffer);
	size = 1;
	while (!ft_strchr(str, '\n') && size)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		temp = str;
		str = ft_strjoin(temp, buffer);
		free(temp);
	}
	pos = 0;
	while(str[pos] != '\0')
	{
		if(str[pos] == '\n')
		{
			pos++;
			break ;
		}
		pos++;
	}
	if(pos == 0 || !str)
		return (NULL);
	new_temp = str;
	line = ft_substr(new_temp, 0, pos);
	// str = ft_strdup((str)[pos]);
	ft_free(new_temp);
	ft_free(buffer);
	if (size == 0 && !line)
	{
		return (NULL);
	}
	return (line);
}

void ft_free(void *var)
{
	free(var);
	var = NULL;
}