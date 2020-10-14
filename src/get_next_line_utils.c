/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:19:25 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/22 16:18:54 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*q;

	if (!s1 || !s2)
		return (NULL);
	if (!(p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *
		sizeof(char))))
		return (NULL);
	q = p;
	while (*s1 != '\0')
		*p++ = *s1++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	return (q);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*q;

	if (!s)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	q = p;
	while (*s != '\0')
		*p++ = *s++;
	*p = '\0';
	return (q);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	j;
	size_t	size;

	j = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (start > size)
		return (ft_strdup(""));
	if (!(p = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < size)
	{
		while (j < len && s[start] != '\0')
		{
			p[j++] = s[start++];
		}
	}
	p[j] = '\0';
	return (p);
}
