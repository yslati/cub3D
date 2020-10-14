/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:02:47 by yslati            #+#    #+#             */
/*   Updated: 2020/02/22 16:18:46 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_swap_dbl(int i, int j, t_cub3d *cub)
{
	double	tmp;

	tmp = cub->sprite_dis[i];
	cub->sprite_dis[i] = cub->sprite_dis[j];
	cub->sprite_dis[j] = tmp;
}

void	ft_swap_int(int i, int j, t_cub3d *cub)
{
	int		tmp;

	tmp = cub->sprite_order[i];
	cub->sprite_order[i] = cub->sprite_order[j];
	cub->sprite_order[j] = tmp;
	ft_swap_dbl(i, j, cub);
}
