/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:03:01 by tneves            #+#    #+#             */
/*   Updated: 2021/02/19 19:38:15 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*set_line(char *saved_buffer)
{
	char	*new_line;
	int		line_length;

	line_length = ft_line_length(saved_buffer);
	if (saved_buffer[line_length] != '\n' && saved_buffer[line_length])
		line_length++;
	new_line = ft_substr(saved_buffer, 0, line_length, 0);
	return (new_line);
}

static char		*clean_static_buffer(char *buffer)
{
	int	line_length;
	int	rest_length;

	line_length = ft_line_length(buffer);
	if (buffer[line_length] != '\n' && buffer[line_length])
		line_length++;
	rest_length = ft_strlen(buffer) - line_length - 1;
	buffer = ft_substr(buffer, line_length + 1, rest_length, buffer);
	return (buffer);
}

int				get_next_line(int fd, char **line)
{
	static char *saved_line;
	char		*buffer;
	int			reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (reader != 0 && !ft_str_has_char(saved_line, '\n'))
	{
		if ((reader = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		saved_line = ft_strjoin(saved_line, buffer);
	}
	free(buffer);
	*line = set_line(saved_line);
	saved_line = clean_static_buffer(saved_line);
	if (reader == 0)
		return (0);
	return (1);
}
