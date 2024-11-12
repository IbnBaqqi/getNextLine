/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:32:56 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/12 19:04:56 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h> //remove later
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

//# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);

#endif
