/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:25:30 by yslati            #+#    #+#             */
/*   Updated: 2020/02/24 16:22:36 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sort_sprite(t_cub3d *cub)
{
	int		i;
	int		j;

	i = -1;
	while (++i < cub->num_sprite - 1)
	{
		j = i;
		while (++j < cub->num_sprite)
		{
			if (cub->sprite_dis[i] < cub->sprite_dis[j])
				ft_swap_int(i, j, cub);
		}
	}
}

void	ft_sprite_order(t_cub3d *cub)
{
	int		i;

	i = -1;
	while (++i < cub->num_sprite)
	{
		cub->sprite_order[i] = i;
		cub->sprite_dis[i] = (cub->ppos_x - cub->sprite_x[i]) *
			(cub->ppos_x - cub->sprite_x[i]) +
			(cub->ppos_y - cub->sprite_y[i]) * (cub->ppos_y - cub->sprite_y[i]);
	}
	ft_sort_sprite(cub);
}

void	ft_draw_sprite(t_cub3d *cub, double transform_y)
{
	int		i;
	int		color;
	int		j;
	int		d;

	i = cub->drawstartx - 1;
	while (++i < cub->drawendx)
	{
		cub->tex_x = (int)(2 * (i - (-cub->sprite_width / 2 +
			cub->sprite_s_x)) * cub->tex_w / cub->sprite_width) / 2;
		j = cub->drawstarty - 1;
		if (transform_y > 0 && i > 0 && i < cub->resolution_x &&
			transform_y < cub->z_buffer[i])
		{
			while (++j < cub->drawendy)
			{
				d = j * 2 - cub->resolution_y + cub->sprite_height;
				cub->tex_y = ft_max((((d * cub->tex_h) /
					cub->sprite_height) / 2), 0);
				color = cub->data_sprite[cub->tex_w * cub->tex_y + cub->tex_x];
				if (color != 9961608)
					cub->data[i + cub->resolution_x * j] = color;
			}
		}
	}
}

void	ft_height_sprite(t_cub3d *cub, double transform_y)
{
	cub->sprite_height = abs((int)(cub->resolution_y / transform_y));
	cub->drawstarty = -cub->sprite_height / 2 + cub->resolution_y / 2;
	cub->drawendy = cub->sprite_height / 2 + cub->resolution_y / 2;
	(cub->drawstarty < 0) ? (cub->drawstarty = 0) : 0;
	(cub->drawstarty >= cub->resolution_y) ?
		(cub->drawendy = cub->resolution_y - 1) : 0;
	(cub->drawendy >= cub->resolution_y) ?
		(cub->drawendy = cub->resolution_y - 1) : 0;
	cub->sprite_width = abs((int)(cub->resolution_y / transform_y));
	cub->drawstartx = -cub->sprite_width / 2 + cub->sprite_s_x;
	(cub->drawstartx < 0) ? (cub->drawstartx = 0) : 0;
	cub->drawendx = cub->sprite_width / 2 + cub->sprite_s_x;
	(cub->drawendx >= cub->resolution_x) ?
		(cub->drawendx = cub->resolution_x - 1) : 0;
	ft_draw_sprite(cub, transform_y);
}

void	ft_sprite(t_cub3d *cub)
{
	double		inv;
	double		transform_x;
	double		transform_y;
	int			i;

	i = -1;
	ft_sprite_order(cub);
	cub->tex_h = cub->reso_sp_y;
	cub->tex_w = cub->reso_sp_x;
	while (++i < cub->num_sprite)
	{
		cub->sprite_p_x = 0.4 + cub->sprite_x[cub->sprite_order[i]] -
			cub->ppos_x;
		cub->sprite_p_y = 0.4 + cub->sprite_y[cub->sprite_order[i]] -
			cub->ppos_y;
		inv = 1.0 / (cub->plane_x * cub->v_dir_y - cub->v_dir_x * cub->plane_y);
		transform_x = inv * (cub->v_dir_y * cub->sprite_p_x -
			cub->v_dir_x * cub->sprite_p_y);
		transform_y = inv * (-cub->plane_y * cub->sprite_p_x +
			cub->plane_x * cub->sprite_p_y);
		cub->sprite_s_x = (int)((cub->resolution_x / 2) *
			(1 + transform_x / transform_y));
		ft_height_sprite(cub, transform_y);
	}
}
