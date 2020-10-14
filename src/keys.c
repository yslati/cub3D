/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:11:45 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 16:24:18 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int key, t_cub3d *cub)
{
	if (key == KEY_A)
		cub->key_a = 1;
	if (key == KEY_S)
		cub->key_s = 1;
	if (key == KEY_D)
		cub->key_d = 1;
	if (key == KEY_W)
		cub->key_w = 1;
	if (key == KEY_LEFT)
		cub->key_left = 1;
	if (key == KEY_RIGHT)
		cub->key_right = 1;
	if (key == KEY_ESC)
		ft_quit_game(cub);
	return (0);
}

int		key_release(int key, t_cub3d *cub)
{
	if (key == KEY_A)
		cub->key_a = 0;
	if (key == KEY_S)
		cub->key_s = 0;
	if (key == KEY_D)
		cub->key_d = 0;
	if (key == KEY_W)
		cub->key_w = 0;
	if (key == KEY_LEFT)
		cub->key_left = 0;
	if (key == KEY_RIGHT)
		cub->key_right = 0;
	return (0);
}

void	ft_screen_move(t_cub3d *cub)
{
	if (cub->key_a)
		ft_move_left(cub);
	if (cub->key_s)
		ft_move_down(cub);
	if (cub->key_d)
		ft_move_right(cub);
	if (cub->key_w)
		ft_move_up(cub);
	if (cub->key_left || cub->key_right)
		ft_rotation_camera(cub);
}

int		icon_exit(void *cub)
{
	(void)cub;
	exit(0);
}
