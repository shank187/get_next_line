/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:23 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/20 17:20:09 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst && !dstsize)
		return (ft_strlen((char *)src));
	i = ft_strlen(dst);
	if (dstsize < i + 1)
		return (ft_strlen((char *)src) + dstsize);
	j = 0;
	while ((dstsize > i + 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	return (i + ft_strlen((char *)src) - j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*c;
	size_t	size;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *) &s[start]);
	size = len + 1;
	if (s_len < len)
		size = s_len + 1;
	c = (char *) malloc(size);
	if (!c)
		return (NULL);
	c[0] = 0;
	ft_strlcat(c, &s[start], size);
	return (c);
}

char	*ft_strjoin(char *s1, char *s2, int is_s2_leak)
{
	size_t	siz;
	char	*c;

	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	siz = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	c = (char *) malloc(siz);
	if (!c)
	{
		if (is_s2_leak)
			free(s2);
		free(s1);
		return (NULL);
	}
	c[0] = 0;
	if (s1)
		ft_strlcat(c, s1, ft_strlen((char *) s1) + 1);
	ft_strlcat(c, s2, siz);
	free(s1);
	if (is_s2_leak)
		free(s2);
	return (c);
}
