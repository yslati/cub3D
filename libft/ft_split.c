/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:55:46 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/15 12:58:57 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if ((*s == c && *(s + 1) != c) || *(s + 1) == '\0')
			len++;
		s++;
	}
	return (len);
}

static int		len_word(char const *s, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static char		**ft_do(char const *s)
{
	char	**ptr;

	ptr = NULL;
	if (!s)
	{
		ptr = (char **)malloc(1 * sizeof(char *));
		ptr[0] = NULL;
	}
	return (ptr);
}

static char		**ft_free_all(char **ptr, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		c_word;

	if ((ptr = ft_do(s)))
		return (ptr);
	c_word = count_word(s, c);
	j = 0;
	if (!(ptr = (char **)malloc(sizeof(char *) * (c_word + 1))))
		return (NULL);
	while (j < c_word)
	{
		while (*s && *s == c)
			s++;
		if (!(ptr[j] = (char *)malloc((len_word(s, c) + 1) * sizeof(char))))
			return (ft_free_all(ptr, c_word));
		i = 0;
		while (*s && *s != c)
			ptr[j][i++] = *s++;
		ptr[j++][i] = '\0';
	}
	ptr[j] = NULL;
	return (ptr);
}
