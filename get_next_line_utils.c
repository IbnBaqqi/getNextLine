/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:34:10 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/12 17:57:58 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = (char )c;
	while (*s != '\0')
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_mem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_mem = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_mem)
		return (NULL);
	while (s1[i] != 0)
	{
		str_mem[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str_mem[i + j] = s2[j];
		j++;
	}
	str_mem[i + j] = '\0';
	return (str_mem);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*c_dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	c_dup = dup;
	while (s[i])
	{
		*c_dup++ = *s++;
	}
	*c_dup = '\0';
	return (dup);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*memory;
	size_t			i;
	size_t			c_size;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	c_size = count * size;
	if (size != 0 && c_size / size != count)
		return (NULL);
	memory = malloc(c_size);
	if (!memory)
		return (NULL);
	while (i < c_size)
	{
		memory[i++] = 0;
	}
	return (memory);
}
