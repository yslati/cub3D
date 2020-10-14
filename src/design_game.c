/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:53:46 by yslati            #+#    #+#             */
/*   Updated: 2020/02/24 16:25:07 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_dd_algo(t_cub3d *cub)
{
	if (cub->ray_dir_x < 0)
	{
		cub->step_x = -1;
		cub->side_dist_x = (cub->ppos_x - cub->map_x) * cub->delta_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_dist_x = (cub->map_x + 1.0 - cub->ppos_x) * cub->delta_x;
	}
	if (cub->ray_dir_y < 0)
	{
		cub->step_y = -1;
		cub->side_dist_y = (cub->ppos_y - cub->map_y) * cub->delta_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_dist_y = (cub->map_y + 1.0 - cub->ppos_y) * cub->delta_y;
	}
}

void	ft_first_block(t_cub3d *cub)
{
	ft_dd_algo(cub);
	cub->hit = 0;
	while (cub->hit == 0)
	{
		if (cub->side_dist_x < cub->side_dist_y)
		{
			cub->side_dist_x += cub->delta_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->side_dist_y += cub->delta_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
		if (cub->map[(int)cub->map_y][(int)cub->map_x] == '1')
			cub->hit = 1;
		side_texture(cub, cub->side);
	}
}

void	ft_height(t_cub3d *cub, int index)
{
	int		drawstart;
	int		drawend;

	if (cub->side == 0)
		cub->perp_wd = (cub->map_x - cub->ppos_x +
		(1 - cub->step_x) / 2) / cub->ray_dir_x;
	else
		cub->perp_wd = (cub->map_y - cub->ppos_y +
		(1 - cub->step_y) / 2) / cub->ray_dir_y;
	cub->line_height = (int)(cub->resolution_y / cub->perp_wd);
	drawstart = -cub->line_height / 2 + cub->resolution_y / 2;
	(drawstart < 0) ? (drawstart = 0) : 0;
	drawend = cub->line_height / 2 + cub->resolution_y / 2;
	(drawend >= cub->resolution_y) ? (drawend = cub->resolution_y - 1) : 0;
	cub->z_buffer[index] = cub->perp_wd;
	ft_draw(drawstart, drawend, index, cub);
}

int		ft_loop_game(t_cub3d *cub)
{
	int		i;

	i = -1;
	ft_screen_move(cub);
	while (++i < cub->resolution_x - 1)
	{
		cub->camera_x = 2 * i / (double)cub->resolution_x - 1;
		cub->ray_dir_x = cub->v_dir_x + cub->plane_x * cub->camera_x;
		cub->ray_dir_y = cub->v_dir_y + cub->plane_y * cub->camera_x;
		cub->map_x = (int)cub->ppos_x;
		cub->map_y = (int)cub->ppos_y;
		cub->delta_x = fabs(1 / cub->ray_dir_x);
		cub->delta_y = fabs(1 / cub->ray_dir_y);
		ft_first_block(cub);
		ft_height(cub, i);
	}
	ft_sprite(cub);
	if (cub->save == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	return (0);
}

int		ft_make_game(t_cub3d *cub)
{
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (-4);
	if (ft_recup_texture(cub) < 0)
		return (-6);
	if ((cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->resolution_x,
		cub->resolution_y, "cub3D")) == NULL)
		return (-5);
	cub->img = mlx_new_image(cub->mlx_ptr, cub->resolution_x,
		cub->resolution_y);
	cub->data = (int *)mlx_get_data_addr(cub->img, &cub->per_pixel,
	&cub->size_line, &cub->endian);
	mlx_hook(cub->win_ptr, KEY_PRESS, KEY_PRESS_MASK, &key_press, cub);
	mlx_hook(cub->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, &key_release, cub);
	mlx_hook(cub->win_ptr, 17, 0, &icon_exit, cub);
	mlx_loop_hook(cub->mlx_ptr, &ft_loop_game, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
