/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:36:25 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/27 12:44:47 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_max(long int res, int sign)
{
	if (res < 0 && sign > 0)
		return (-1);
	if (res > 0 && sign < 0)
		return (0);
	return (res);
}

int				ft_atoi(const char *str)
{
	int			sign;
	int			rst;

	sign = 1;
	rst = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst *= 10;
		rst += *str - '0';
		str++;
	}
	rst = rst * sign;
	return (ft_max(rst, sign));
}
