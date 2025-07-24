/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:27:05 by aelbour           #+#    #+#             */
/*   Updated: 2025/07/24 10:39:10 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimization.h"



char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	j = ft_strlen((char *) s);
	i = 0;
	while (i <= j)
		if (s[i++] == (char)c)
			return ((char *) &s[--i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (!dstsize)
		return (src_len);
	if (!src)
	{
		dst = NULL;
		return (-1);
	}
	while ((i < dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

char	*ft_strdup(const char *s1)
{
	char	*c;
	size_t	i;
	size_t	l;

	l = ft_strlen((char *) s1);
	i = 0;
	c = (char *) malloc(l + 1);
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, l + 1);
	return (c);
}


char *get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	char		*line;
	int			i;

	i = 0;
	if (!str)
	{
		str = malloc(BUFFER_SIZE + 1);
		str[0] = 0;
	}
	if (!str)
		return (NULL);
		line = malloc(BUFFER_SIZE + 1);
	if(!line)
		return (free(line), NULL);
	if (read(fd, line, 0) == -1)
		return (free(line), free(str), str = NULL, NULL);
	i = read(fd, line, BUFFER_SIZE);
	while(i)
	{
		line[i] = 0;
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		if (ft_strchr(str, '\n'))
			break;
		i = read(fd, line, BUFFER_SIZE);
	}
	if (str && str[0])
	{
		tmp = line;
		line = ft_substr(str, 0, ft_strlen_chr(str, '\n') + 1);
		free(tmp);
		tmp = str;
		str = ft_strdup(ft_strchr(str, '\n') + 1);
		free(tmp);
		return (line);
	}
	return (free(line), NULL);
}

int main(void)
{
	int i = 0;
	char *s;
	i = open("optimization.h", O_RDONLY);
	
	s = get_next_line(i);
	while(s)
	{
		printf("%s", s);
		s = get_next_line(i);
	}
	s = get_next_line(i);
	printf("%s", s);
}