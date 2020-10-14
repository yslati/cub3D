/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:37:26 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/22 16:18:44 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_texture_no(t_cub3d *cub)
{
	char	*text;

	text = ft_strtrim(cub->north, " ");
	if (!(cub->texture_north = mlx_xpm_file_to_image(cub->mlx_ptr,
		text, &cub->reso_no_x, &cub->reso_no_y)))
		return (-1);
	cub->data_north = (int *)mlx_get_data_addr(cub->texture_north,
	&cub->pp_north, &cub->sl_north, &cub->endian_no);
	free(text);
	return (0);
}

int		ft_texture_so(t_cub3d *cub)
{
	char	*text;

	text = ft_strtrim(cub->south, " ");
	if (!(cub->texture_south = mlx_xpm_file_to_image(cub->mlx_ptr,
		text, &cub->reso_so_x, &cub->reso_so_y)))
		return (-1);
	cub->data_south = (int *)mlx_get_data_addr(cub->texture_south,
	&cub->pp_south, &cub->sl_south, &cub->endian_so);
	free(text);
	return (0);
}

int		ft_texture_we(t_cub3d *cub)
{
	char	*text;

	text = ft_strtrim(cub->west, " ");
	if (!(cub->texture_west = mlx_xpm_file_to_image(cub->mlx_ptr,
		text, &cub->reso_we_x, &cub->reso_we_y)))
		return (-1);
	cub->data_west = (int *)mlx_get_data_addr(cub->texture_west,
	&cub->pp_west, &cub->sl_west, &cub->endian_we);
	free(text);
	return (0);
}

int		ft_texture_es(t_cub3d *cub)
{
	char	*text;

	text = ft_strtrim(cub->east, " ");
	if (!(cub->texture_east = mlx_xpm_file_to_image(cub->mlx_ptr,
		text, &cub->reso_ea_x, &cub->reso_ea_y)))
		return (-1);
	cub->data_east = (int *)mlx_get_data_addr(cub->texture_east,
	&cub->pp_east, &cub->sl_east, &cub->endian_ea);
	free(text);
	return (0);
}

int		ft_texture_sp(t_cub3d *cub)
{
	char	*text;

	text = ft_strtrim(cub->sprite, " ");
	if (!(cub->texture_sprite = mlx_xpm_file_to_image(cub->mlx_ptr,
		text, &cub->reso_sp_x, &cub->reso_sp_y)))
		return (-1);
	cub->data_sprite = (int *)mlx_get_data_addr(cub->texture_sprite,
	&cub->pp_sprite, &cub->sl_sprite, &cub->endian_sp);
	free(text);
	return (0);
}
