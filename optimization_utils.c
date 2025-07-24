/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:33:25 by aelbour           #+#    #+#             */
/*   Updated: 2025/07/24 10:48:44 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimization.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*c;
	size_t	size;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *) s);
	if (start > s_len)
		return (ft_strdup(""));
	s_len = ft_strlen((char *) &s[start]);
	size = len + 1;
	if (s_len < len)
		size = s_len + 1;
	c = (char *) malloc(size);
	if (!c)
		return (NULL);
	ft_strlcpy(c, &s[start], size);
	return (c);
}

int ft_strlen_chr(char *str, char chr)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != chr && str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst && !dstsize)
		return (ft_strlen((char *)src));
	if (!src)
	{
		dst = NULL;
		return (-1);
	}
	i = ft_strlen(dst);
	if (dstsize < i + 1)
		return (ft_strlen((char *)src) + dstsize);
	j = 0;
	while ((dstsize > i + 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	return (i + ft_strlen((char *)src) - j);
} 

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	siz;
	char	*c;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	siz = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	c = (char *) malloc(siz);
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, ft_strlen((char *) s1) + 1);
	ft_strlcat(c, s2, siz);
	return (c);
}