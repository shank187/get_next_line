/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:06 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/18 16:58:23 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			ft_strlcat((*s), (*s) + j,BUFFER_SIZE);
			return(42);
		}
	}
	if(j)
		(*l) = ft_strdup((*s));
	free(*s);
	(*s) = NULL; 
	return(0);
}

char	*get_ln(char **s, char **l, int fd)
{
	int		i;
	int	j;

	i = 1;
	while (i)
	{
		i = read(fd, (*s), BUFFER_SIZE);
		if(i < 0)
		{
			free(*s);
			(*s) = NULL;
			(*l) = NULL;
			return (*l);
		}
		j = 0;
		(*s)[i] = 0;
		while ((*s)[j] && i > 0 && j < i)
		{
			if ((*s)[j++] == '\n')
			{
				(*l) = ft_strjoin((*l), ft_substr((*s), 0, j) , 13);
				(*s)[0] = 0;
				ft_strlcat((*s), (*s) + j, i - j + 1);
				return(*l);
			}
		}
		if (i > 0 && j)
			(*l) = ft_strjoin((*l), (*s), 0);
	}
	free(*s);
	(*s) = NULL;
	return (*l);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*l;
	if(fd < 0 || read(fd, NULL, 0) < 0)
		return(NULL);
	l = NULL;
	if (s)
		if (manage_prevs(&s, &l))
			return(l);
	if (!s && fd >= 0)
		s = malloc(BUFFER_SIZE + 1);
		if(!s)
			return(NULL);
	if (fd >= 0)
		l = get_ln(&s, &l, fd);
	if (!l ) 
	{
		free(s);
		s = NULL;
	}
	return (l);
}
