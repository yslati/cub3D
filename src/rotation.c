/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:04:52 by yslati            #+#    #+#             */
/*   Updated: 2020/02/24 16:09:43 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		rotation_right(double *old_dir_x, double *old_plan_x, t_cub3d *cub)
{
	if (cub->key_right)
	{
		*old_dir_x = cub->v_dir_x;
		cub->v_dir_x = cub->v_dir_x * cos(ROT_SPEED) -
			cub->v_dir_y * sin(ROT_SPEED);
		cub->v_dir_y = *old_dir_x * sin(ROT_SPEED) +
			cub->v_dir_y * cos(ROT_SPEED);
		*old_plan_x = cub->plane_x;
		cub->plane_x = cub->plane_x * cos(ROT_SPEED) -
			cub->plane_y * sin(ROT_SPEED);
		cub->plane_y = *old_plan_x * sin(ROT_SPEED) +
			cub->plane_y * cos(ROT_SPEED);
	}
}

void		ft_rotation_camera(t_cub3d *cub)
{
	double		old_dir_x;
	double		old_plan_x;

	if (cub->key_left)
	{
		old_dir_x = cub->v_dir_x;
		cub->v_dir_x = cub->v_dir_x * cos(-ROT_SPEED) -
			cub->v_dir_y * sin(-ROT_SPEED);
		cub->v_dir_y = old_dir_x * sin(-ROT_SPEED) +
			cub->v_dir_y * cos(-ROT_SPEED);
		old_plan_x = cub->plane_x;
		cub->plane_x = cub->plane_x * cos(-ROT_SPEED) -
			cub->plane_y * sin(-ROT_SPEED);
		cub->plane_y = old_plan_x * sin(-ROT_SPEED) +
			cub->plane_y * cos(-ROT_SPEED);
	}
	rotation_right(&old_dir_x, &old_plan_x, cub);
}
