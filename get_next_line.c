/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:33:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/05 16:50:28 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <>
//ssize_t read(int fd, void *buf, size_t count);

char *get_next_line(int fd)
{
	static char		*left;
	ssize_t			read_byte;
	char			buf[BUFFER_SIZE];
	char			*check_nl;

	read_byte = read(fd, buf, 5);
	if (read_byte < 0)
		perror("Byte is cooked");
	while (read_byte != 0 && (buf))
	{
		check_nl = ft_strchr(read_byte, '\n');
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
