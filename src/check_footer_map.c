/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_footer_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:41:21 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 15:44:41 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double		check_player_pos(t_cub3d *cub, double inc)
{
	if (cub->j < cub->resolution_x / 2 && cub->i < cub->resolution_y / 2)
		inc = 0.5;
	else if (cub->j > cub->resolution_x / 2 && cub->i > cub->resolution_y / 2)
		inc = -0.5;
	return (inc);
}

int			ft_check_char_map(char c, int player, t_cub3d *cub)
{
	double		inc;

	inc = 0;
	if (c == '2' && cub->j != 0)
	{
		cub->sprite_x[cub->num_sprite] = cub->j;
		cub->sprite_y[cub->num_sprite] = cub->i;
		cub->num_sprite++;
	}
	if (c == '\n' || c == '0' || c == '1' || c == '2' || c == '\0')
		return (player);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && player == 2)
		return (0);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && player == 1)
	{
		if (cub->j == 0)
			return (0);
		else
			inc = check_player_pos(cub, inc);
		cub->ppos_x = cub->j + inc;
		cub->ppos_y = cub->i + inc;
		ft_init_vecteur_direction(c, cub);
		return (player + 1);
	}
	return (1);
}

int			ft_check_board_map(t_cub3d *cub)
{
	cub->i = 0;
	while (cub->i < cub->size_map_y)
	{
		cub->j = 0;
		while (cub->j < cub->size_map_x)
		{
			if ((cub->map[cub->i][cub->j] != '1' &&
				cub->map[cub->i][cub->j] != '\n')
				&& (((cub->i == 0 || cub->i == cub->size_map_y - 1)) ||
					((cub->j == cub->size_map_x - 1) || (cub->j == 0))))
				return (-1);
			cub->j++;
		}
		cub->i++;
	}
	return (0);
}

int			ft_check_map_size(t_cub3d *cub, int player)
{
	int		len;
	int		i;

	i = 0;
	cub->size_map_x = ft_map_width(cub->map);
	cub->size_map_y = ft_map_height(cub->map);
	len = (int)ft_strlen(cub->map[0]);
	while (cub->map[++i])
		if (len != (int)ft_strlen(cub->map[i]))
			return (-1);
	cub->i = -1;
	while (++cub->i < cub->size_map_y)
	{
		cub->j = -1;
		while (++cub->j < cub->size_map_x)
		{
			if (!(player = ft_check_char_map(cub->map[cub->i][cub->j],
				player, cub)))
				return (-1);
		}
	}
	if (player != 2)
		return (-1);
	return (0);
}
