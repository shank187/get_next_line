/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:06 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/16 21:50:14 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	manage_prevs(char **s, char **l)
{
	size_t	j;
	char	*c;

	j = 0;
	// printf("func call\n");
	while ((*s)[j])
	{
		if ((*s)[j++] == '\n')
		{
			(*l) = ft_substr((*s), 0, j);
			(*s)[0] = 0;
			ft_strlcat((*s), (*s) + j,BUFFER_SIZE);
			// printf("%s\n",*s);
			return(42);
		}
	}
	(*l) = ft_strdup((*s));
	// printf("%s\n",*l);
	free(*s);
	(*s) = NULL; 
	return(0);
}

char	*get_line(char **s, char **l, int fd)
{
	int		i;
	size_t	j;

	i = 1;
	while (i)
	{
		i = read(fd, (*s), BUFFER_SIZE);
		j = 0;
		// printf("%i\n",i);
		while ((*s)[j] && i && j < i)
		{
			if ((*s)[j++] == '\n')
			{
				(*l) = ft_strjoin((*l), ft_substr((*s), 0, j) , 13);
				(*s)[0] = 0;
				ft_strlcat((*s), (*s) + j,BUFFER_SIZE);
				return(*l);
			}
		}
		if (i > 0 && j)
			(*l) = ft_strjoin((*l), ft_substr((*s), 0, i), 42);
	}
	free(*s);
	(*s) = NULL;
	return (*l);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*l;

	l = NULL;
	if (s)
		if (manage_prevs(&s, &l))
			return(l);
	if (!s && fd >= 0)
		s = malloc(BUFFER_SIZE + 1);
	if (fd >= 0)
		l = get_line(&s, &l, fd);
	if (!l ) 
	{
		free(s);
		s = NULL;
	}
	return (l);
}
