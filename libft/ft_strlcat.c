/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:55:33 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/15 12:59:18 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	s_len;
	size_t	d_len;
	size_t	len;
	size_t	i;

	s = (char *)src;
	s_len = ft_strlen(src);
	if (!dst && !size)
		return (s_len);
	d_len = ft_strlen(dst);
	len = d_len;
	i = 0;
	if (size <= d_len)
		return (size + s_len);
	else if (size > d_len)
	{
		while (s[i] && d_len < size - 1)
			dst[d_len++] = s[i++];
		dst[d_len] = '\0';
		return (s_len + len);
	}
	return (0);
}
