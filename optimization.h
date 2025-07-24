/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:33:37 by aelbour           #+#    #+#             */
/*   Updated: 2025/07/24 10:48:42 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
int ft_strlen_chr(char *str, char chr);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char *get_next_line(int fd);

 
#endif