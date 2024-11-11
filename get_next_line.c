/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:33:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/11 17:34:29 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

char 	*get_next_line(int fd)
{
	static char		left;
	char			*line;
	ssize_t			read_byte;
	static char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_file(fd, buf);
		if(!buf)
			return (NULL);
}

//To read the file;
static char *read_file(int fd, char *buf)
{
	char	*buf_new;
	int		read_byte;

	if(!buf)
		return(0); //Change to return dynamic later
	buf_new = malloc(BUFFER_SIZE + 1);
	read_byte = 1;
	while (read_byte != 0)
	{
		read_byte = read(fd, buf_new, BUFFER_SIZE);
		if (read_byte == -1)
			return (0);
		buf_new[read_byte] = 0;
		buf = add_buf(buf, buf_new);
		if (ft_strchr(buf_new, '\n'))
			break;
	}
	free(buf_new);
	return (buf);
}

//To join allocated buf to buffer
static char	*add_buf(char *buf_new, char *buf)
{
	char	*new_buf;
	
	new_buf = ft_strjoin(buf_new, buf);
	free(buf_new);
	return (new_buf);
}

static char	*get_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if(!*buf)
		return (NULL);
	while(buf[i] && buf[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("Doc.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}

/*

asd
ds

while (read_byte != 0)
    {
        if (!ft_strchr(buf, '\n'))
            continue;
        else
        {
            char nl_point = ft_strchr(buf, '\n');
            break;
        }
    }
    char *buffer = malloc(nl_point - buf);
    if(!buffer)
        return (NULL);
    ft_strlcpy(buffer, buf, (nl_point - buf) + 1);



char 	*get_next_line(int fd)
{
	static char		left;
	ssize_t			read_byte;
	static char		*buf;
	int				check_nl;
	int				count;
	char			*new_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read_byte != 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (0);
		else if (read_byte == 0)
			break;
		count++;
		if (!(check_nl(buf, count, BUFFER_SIZE)))
			continue;
		else
		{
			char *new_buf = add_buf(buf, count, BUFFER_SIZE);
			break;
		}
	}
	free(buf);
	return (new_buf);
}

//To read the file;
static *char read_file()
{
	
}

//To add the line to buffer
static char	*add_buf(char *buf, int count, size_t BUFFER_SIZE)
{
	int			i;
	int			size;
	static char	*left;
	char		*new_buf;

	i = 0;
	while (buf[i++] != '\n')
		size++;
	new_buf = malloc(size + 1);
	ft_strlcpy(new_buf, buf, size + 1);// change the ft_strlcpy to '\n' instead of '\0'
	buf[count * BUFFER_SIZE] = '\0';
	left = ft_strdup(buf[size]);
	return (new_buf);
}

//To check is the buffer has newline
static int	check_nl(char *buf, int count, int buf_size)
{
	int	i;
	int	length;

	i = 0;
	length = count * buf_size;
	while (i < length)
	{
		if (buf[i] = '\n')
			return (1);
	}
	return (0);
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("Doc.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
*/
