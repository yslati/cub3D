/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:22:45 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 20:11:30 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_left(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x + cub->v_dir_y *
		MOVE_SPEED)] != '1')
		cub->ppos_x += cub->v_dir_y * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y - cub->v_dir_x * MOVE_SPEED)]
		[(int)(cub->ppos_x)] != '1')
		cub->ppos_y -= cub->v_dir_x * MOVE_SPEED;
}

void	ft_move_right(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x - cub->v_dir_y *
		MOVE_SPEED)] != '1')
		cub->ppos_x -= cub->v_dir_y * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y + cub->v_dir_x * MOVE_SPEED)]
		[(int)(cub->ppos_x)] != '1')
		cub->ppos_y += cub->v_dir_x * MOVE_SPEED;
}

void	ft_move_up(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x + cub->v_dir_x *
		MOVE_SPEED)] != '1')
		cub->ppos_x += cub->v_dir_x * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y + cub->v_dir_y * MOVE_SPEED)]
		[(int)(cub->ppos_x)] != '1')
		cub->ppos_y += cub->v_dir_y * MOVE_SPEED;
}

void	ft_move_down(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x - cub->v_dir_x *
		MOVE_SPEED)] != '1')
		cub->ppos_x -= cub->v_dir_x * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y - cub->v_dir_y * MOVE_SPEED)]
		[(int)(cub->ppos_x)] != '1')
		cub->ppos_y -= cub->v_dir_y * MOVE_SPEED;
}
