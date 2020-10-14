/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:35:59 by yslati            #+#    #+#             */
/*   Updated: 2020/02/25 16:58:02 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_east(char c, t_cub3d *cub)
{
	if (c == 'E')
	{
		cub->v_dir_x = 0.99;
		cub->v_dir_y = 0.00;
		cub->plane_y = 0.66;
		cub->plane_x = 0.00;
	}
}

void		ft_init_vecteur_direction(char c, t_cub3d *cub)
{
	if (c == 'N')
	{
		cub->v_dir_x = 0.00;
		cub->v_dir_y = -0.99;
		cub->plane_x = 0.66;
		cub->plane_y = 0.00;
	}
	if (c == 'S')
	{
		cub->v_dir_x = 0.00;
		cub->v_dir_y = 0.99;
		cub->plane_x = -0.66;
		cub->plane_y = 0.00;
	}
	if (c == 'W')
	{
		cub->v_dir_x = -0.99;
		cub->v_dir_y = 0.00;
		cub->plane_y = -0.66;
		cub->plane_x = 0.00;
	}
	init_east(c, cub);
}

void		ft_init_cub(t_cub3d *cub)
{
	cub->flag_north = 0;
	cub->flag_south = 0;
	cub->flag_east = 0;
	cub->flag_west = 0;
	cub->flag_floor = 0;
	cub->flag_resolution = 0;
	cub->flag_sprite = 0;
	cub->flag_ceiling = 0;
	cub->save = 0;
	cub->i = 0;
	cub->j = 0;
	cub->key_a = 0;
	cub->key_s = 0;
	cub->key_d = 0;
	cub->key_w = 0;
	cub->key_left = 0;
	cub->key_right = 0;
	cub->num_sprite = 0;
	cub->resolution_x = 0;
	cub->resolution_y = 0;
}

void		ft_init_bmp(t_save *save)
{
	save->index = 0;
	save->size = 0;
	save->bmp = NULL;
}
