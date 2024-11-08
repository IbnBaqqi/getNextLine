/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:33:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/08 01:47:22 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE = 1024
//#include <>
//ssize_t read(int fd, void *buf, size_t count);
// Buffer size when compiling.

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
*/
