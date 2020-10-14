/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:53:32 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/15 12:59:10 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*ptr1;
	size_t	l;

	l = ft_strlen(s1);
	if ((ptr = (char *)malloc((l + 1) * sizeof(char))) == NULL)
		return (NULL);
	ptr1 = ptr;
	while (*s1 != '\0')
	{
		*ptr++ = *s1++;
	}
	*ptr = '\0';
	return (ptr1);
}
