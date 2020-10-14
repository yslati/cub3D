/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:33:38 by yslati            #+#    #+#             */
/*   Updated: 2020/02/22 16:18:43 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_texture(t_cub3d *cub)
{
	if (cub->side == 0)
		cub->wall_x = cub->ppos_y + cub->perp_wd * cub->ray_dir_y;
	else
		cub->wall_x = cub->ppos_x + cub->perp_wd * cub->ray_dir_x;
	cub->wall_x = cub->wall_x - (int)cub->wall_x;
	cub->tex_x = cub->wall_x * (double)cub->tex_w;
	if (cub->side == 0 && cub->ray_dir_x < 0)
		cub->tex_x = cub->tex_w - cub->tex_x - 1;
	if (cub->side == 1 && cub->ray_dir_y > 0)
		cub->tex_x = cub->tex_w - cub->tex_x - 1;
}

int		ft_recup_texture(t_cub3d *cub)
{
	int	r;

	r = 0;
	r += ft_texture_we(cub);
	r += ft_texture_so(cub);
	r += ft_texture_no(cub);
	r += ft_texture_es(cub);
	r += ft_texture_sp(cub);
	return (r);
}

void	ft_choose_texture(t_cub3d *cub)
{
	if (cub->text == 0)
	{
		cub->tex_h = cub->reso_so_y;
		cub->tex_w = cub->reso_so_x;
		cub->data_print = cub->data_south;
	}
	else if (cub->text == 1)
	{
		cub->tex_h = cub->reso_ea_y;
		cub->tex_w = cub->reso_ea_x;
		cub->data_print = cub->data_east;
	}
	else if (cub->text == 2)
	{
		cub->tex_h = cub->reso_no_y;
		cub->tex_w = cub->reso_no_x;
		cub->data_print = cub->data_north;
	}
	else if (cub->text == 3)
	{
		cub->tex_h = cub->reso_we_y;
		cub->tex_w = cub->reso_we_x;
		cub->data_print = cub->data_west;
	}
}

void	side_texture(t_cub3d *cub, int i)
{
	if (i == 0)
	{
		if (cub->map_x - (int)cub->ppos_x > 0)
			cub->text = 2;
		else
			cub->text = 0;
	}
	else
	{
		if (cub->map_y - (int)cub->ppos_y > 0)
			cub->text = 3;
		else
			cub->text = 1;
	}
}
