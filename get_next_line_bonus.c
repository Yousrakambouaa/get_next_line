/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:06:27 by ykamboua          #+#    #+#             */
/*   Updated: 2024/04/03 06:53:26 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_buffer(int fd, char **left)
{
	ssize_t	read_bytes;
	char	*buffer;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((read_bytes > 0) && !ft_strchr(*left, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		*left = ft_strjoin(*left, buffer);
	}
	ft_free(&buffer);
	return (*left);
}

char	*extract_line(char **left)
{
	char	*line;
	char	*nl_index;
	char	*left_cp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	left_cp = *left;
	nl_index = ft_strchr(*left, '\n');
	if (!nl_index)
		return (line = ft_strdup(*left), ft_free(left), line);
	while (left_cp[len] && left_cp[len] != '\n')
		len++;
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	while (left_cp[i] && i < len + 1)
	{
		line[i] = left_cp[i];
		i++;
	}
	line[i] = '\0';
	*left = ft_strdup(nl_index + 1);
	return (free(left_cp), line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&left[fd]), NULL);
	left[fd] = fill_buffer(fd, &left[fd]);
	if (!left[fd])
		return (NULL);
	line = extract_line(&left[fd]);
	return (line);
}
