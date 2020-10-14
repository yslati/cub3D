/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:19:16 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/15 12:59:14 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr1;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *
		sizeof(char))))
		return (NULL);
	ptr1 = ptr;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr1);
}
