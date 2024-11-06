/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:33:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/06 19:35:13 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <>
//ssize_t read(int fd, void *buf, size_t count);
// Buffer size when compiling.

char 	*get_next_line(int fd)
{
	static char		left;
	ssize_t			read_byte;
	static char		*buf;
	char			*check_nl;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read_byte != 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
        perror("Byte is cooked");
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
}



asd
ds

/*
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
