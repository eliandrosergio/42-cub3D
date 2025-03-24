/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:17:07 by efaustin          #+#    #+#             */
/*   Updated: 2024/06/18 16:17:09 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_unite(char *buffer, char *tempbuf)
{
	char	*tmp;

	if (!buffer || !tempbuf)
		return (NULL);
	tmp = ft_strjoin(buffer, tempbuf);
	free(buffer);
	return (tmp);
}

static char	*ft_read_file(char *buffer, int fd)
{
	char	*tempbuf;
	int		bread;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	tempbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bread = read(fd, tempbuf, BUFFER_SIZE);
	while (tempbuf && bread > 0)
	{
		tempbuf[bread] = '\0';
		buffer = ft_unite(buffer, tempbuf);
		if (!buffer || ft_strrchr(buffer, '\n'))
			break ;
		bread = read(fd, tempbuf, BUFFER_SIZE);
	}
	free(tempbuf);
	if (buffer && (bread < 0 || buffer[0] == '\0'))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (buffer);
}

static char	*ft_find_line(char *buffer)
{
	char	*line;
	size_t	index;

	if (!buffer)
		return (NULL);
	index = 0;
	while (buffer[index] != '\n' && buffer[index])
		index++;
	line = ft_calloc(index + 2, sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] != '\n' && buffer[index])
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] && buffer[index] == '\n')
		line[index] = '\n';
	return (line);
}

static char	*ft_change_buffer(char *buffer)
{
	char	*newbuf;
	size_t	i;
	size_t	j;

	i = 0;
	if (!buffer)
		return (NULL);
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i])
		i++;
	newbuf = ft_calloc((ft_strlen(buffer) - i) + 1, sizeof(char));
	if (!newbuf)
		return (NULL);
	while (buffer[i])
		newbuf[j++] = buffer[i++];
	free(buffer);
	return (newbuf);
}

char	*get_next_line(int fd, int cleangnl)
{
	static char	*buffer[FOPEN_MAX];
	char		*current;

	if (cleangnl)
	{
		gnl_clean(buffer);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer[fd] = ft_read_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	current = ft_find_line(buffer[fd]);
	buffer[fd] = ft_change_buffer(buffer[fd]);
	return (current);
}
