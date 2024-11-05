/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:33:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/05 01:17:26 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <>
//ssize_t read(int fd, void buf[.count], size_t count);

char *get_next_line(int fd)
{
	
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("Doc.txt", O_RDONLY);
	line = get_next_line(fd);
}