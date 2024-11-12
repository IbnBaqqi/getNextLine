/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:33:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/12 19:13:06 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *buf);
static char	*add_buf(char *buf_new, char *buf);
static char	*get_line(char *buf);
static char	*get_next(char *buf);

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_file(fd, buf);
	if (!buf)
		return (NULL);
	line = get_line(buf);
	buf = get_next(buf);
	return (line);
}

//To read the file;
static char	*read_file(int fd, char *buf)
{
	char	*buf_new;
	ssize_t	read_byte;

	if (!buf)
		buf = ft_strdup("");
	buf_new = malloc(BUFFER_SIZE + 1);
	if (!buf_new)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buf_new, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf_new);
			free(buf);
			return (NULL);
		}
		buf_new[read_byte] = 0;
		buf = add_buf(buf, buf_new);
		if (ft_strchr(buf_new, '\n'))
			break ;
	}
	free(buf_new);
	return (buf);
}

//To join allocated buf to buffer and free
static char	*add_buf(char *buf, char *buf_new)
{
	char	*new_buf;

	new_buf = ft_strjoin(buf, buf_new);
	free(buf);
	return (new_buf);
}

static char	*get_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

static char	*get_next(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	free(buf);
	return (line);
}

/*int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("Doc.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);

		i++;
	}
	close(fd);
	return (0);
}*/
