/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:06 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/15 12:46:28 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_prevs(char **s, char **l)
{
	size_t	j;
	char	*c;

	j = 0;
	while ((*s)[j])
	{
		if ((*s)[j++] == '\n')
		{
			(*l) = ft_substr((*s), j , ft_strlen((*s)));
			free(*s);
			(*s) = NULL;
			return ;
		}
	}
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
		while ((*s)[j] && i)
			if ((*s)[j++] == '\n')
				return (ft_strjoin((*l), ft_substr((*s), 0, j)));
		if (i > 0 && j)
			(*l) = ft_strjoin((*l), (*s));
		else if (i <= 0)
		{
			free(*s);
			free(*l);
			(*s) = NULL;
			(*l) = NULL;
		}
	}
	return (*l);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*l;

	l = NULL;
	if (s)
		manage_prevs(&s, &l);
	if (!s && fd >= 0)
	{
		s = malloc(BUFFER_SIZE + 1);
		// printf("%p\n",s);
		if(!s)
			return (NULL);
	}
	if (fd >= 0)
		l = get_line(&s, &l, fd);
	// printf("%p\n",s);
	if (!l || !s)
	{
		free(s);
		free(l);
	}
	return (l);
}
