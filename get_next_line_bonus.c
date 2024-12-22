/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:06 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/22 18:24:09 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	manage_prevs(char **s, char **l)
{
	size_t	j;

	j = 0;
	while ((*s)[j])
	{
		if ((*s)[j++] == '\n')
		{
			(*l) = ft_substr((*s), 0, j);
			(*s)[0] = 0;
			ft_strlcat((*s), (*s) + j, BUFFER_SIZE);
			xd(s, l, -13, -37);
			return (42);
		}
	}
	if (j)
	{
		(*l) = ft_substr((*s), 0, ft_strlen(*s));
		xd(s, l, -42, -13);
		if (!(*l))
			return (13);
	}
	free(*s);
	(*s) = NULL;
	return (0);
}

char	*xd(char **s, char **l, int j, int i)
{
	if (i < 0 && j < 0)
	{
		if (!(*l))
		{
			free(*s);
			free(*l);
			(*s) = NULL;
		}
		return ((*l));
	}
	(*l) = ft_strjoin((*l), ft_substr((*s), 0, j), 13);
	(*s)[0] = 0;
	ft_strlcat((*s), (*s) + j, i - j + 1);
	return (*l);
}

char	*get_ln(char **s, char **l, int fd)
{
	int	i;
	int	j;

	i = 1;
	while (i)
	{
		i = read(fd, (*s), BUFFER_SIZE);
		j = 0;
		(*s)[i] = 0;
		while ((*s)[j] && i > 0 && j < i)
			if ((*s)[j++] == '\n' && j >= 0 && i >= 0)
				return (xd(s, l, j, i));
		if (i > 0 && j > 0)
			(*l) = ft_strjoin((*l), (*s), 0);
		if (!(*l))
			return (NULL);
	}
	free(*s);
	(*s) = NULL;
	return (*l);
}


char	*get_next_line(int fd)
{
	static char	**s;
	char		*l;
	int i;

	l = NULL;
	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!s && BUFFER_SIZE > 0 && BUFFER_SIZE <= INT_MAX)
	{
		s = malloc(OPEN_MAX * sizeof(char *));
		while(s && i < OPEN_MAX)
			s[i++] = NULL;		
	}
	if (s && s[fd])
		if (manage_prevs(&s[fd], &l))
			return (l);
	if(s && !s[fd])
		s[fd] = malloc((size_t)BUFFER_SIZE + 1);	
	if(s && s[fd])
		l = get_ln(&s[fd], &l, fd);
	if (s && !l)
		return (free(s[fd]), s[fd] = NULL, NULL);
	return (l);
}
