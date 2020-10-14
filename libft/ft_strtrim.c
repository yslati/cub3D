/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:36:49 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/15 12:59:48 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (set[i])
	{
		if (s1[k] == set[i])
		{
			++k;
			i = -1;
		}
		i++;
	}
	return (k);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (s1[k])
		k++;
	k--;
	while (set[i])
	{
		if (s1[k] == set[i])
		{
			--k;
			i = -1;
		}
		i++;
	}
	return (k);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ptr;

	if (!s1)
		return (NULL);
	start = find_start(s1, set);
	if (!s1[start])
		return (ft_substr(s1, 0, 0));
	end = find_end(s1, set);
	len = end - start + 1;
	ptr = ft_substr(s1, start, len);
	return (ptr);
}
