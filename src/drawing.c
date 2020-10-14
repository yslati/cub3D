/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:35:22 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 16:11:44 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_max(int a, int b)
{
	int		r;

	if (a < 0)
		a = 0;
	r = a - b;
	return (r);
}

void	ft_draw(int start, int end, int index, t_cub3d *cub)
{
	int		j;
	int		k;

	j = -1;
	ft_choose_texture(cub);
	ft_texture(cub);
	while (++j < start)
		cub->data[index + cub->resolution_x * j] = (cub->ceiling_r << 16) +
			(cub->ceiling_g << 8) + cub->ceiling_b;
	j = start - 1;
	while (++j < end)
	{
		k = j * 2 - cub->resolution_y + cub->line_height;
		cub->tex_y = ft_max((((k * cub->tex_h) / cub->line_height) / 2), 0);
		cub->data[index + cub->resolution_x * j] =
		cub->data_print[cub->tex_w * cub->tex_y + cub->tex_x];
	}
	while (++j < cub->resolution_y)
		cub->data[index + cub->resolution_x * j] = (cub->floor_r << 16)
			+ (cub->floor_g << 8) + cub->floor_b;
}
