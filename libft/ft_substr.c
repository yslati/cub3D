/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:14:46 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/15 12:59:52 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	size;

	j = 0;
	if (!s)
		return (NULL);
	if (!s[start])
		return (ft_strdup(""));
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (!(ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < size)
	{
		while (j < len && s[start] != '\0')
		{
			ptr[j++] = s[start++];
		}
	}
	ptr[j] = '\0';
	return (ptr);
}
