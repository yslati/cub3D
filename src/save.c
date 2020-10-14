/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:58:42 by yslati            #+#    #+#             */
/*   Updated: 2020/02/27 12:42:30 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	write_int(t_save *save, unsigned int val)
{
	save->bmp[save->index++] = val >> 0;
	save->bmp[save->index++] = val >> 8;
	save->bmp[save->index++] = val >> 16;
	save->bmp[save->index++] = val >> 24;
}

static void	write_file_header(t_save *save)
{
	save->bmp[save->index++] = 'B';
	save->bmp[save->index++] = 'M';
	write_int(save, save->size);
	write_int(save, 0x00000000);
	save->bmp[save->index++] = 54;
	save->bmp[save->index++] = 0;
	save->bmp[save->index++] = 0;
	save->bmp[save->index++] = 0;
}

static void	write_file_info(t_cub3d *cub, t_save *save)
{
	int		i;

	save->bmp[save->index++] = 40;
	save->bmp[save->index++] = 0;
	save->bmp[save->index++] = 0;
	save->bmp[save->index++] = 0;
	write_int(save, cub->resolution_x);
	write_int(save, cub->resolution_y);
	save->bmp[save->index++] = 1;
	save->bmp[save->index++] = 0;
	save->bmp[save->index++] = 24;
	save->bmp[save->index++] = 0;
	i = 0;
	while (i < 24)
	{
		save->bmp[save->index++] = 0;
		i++;
	}
}

static void	write_body(t_cub3d *cub, t_save *save)
{
	int		x;
	int		y;

	y = cub->resolution_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->resolution_x)
		{
			save->bmp[save->index++] = cub->screen
				[y * cub->resolution_x + x] >> 0;
			save->bmp[save->index++] = cub->screen
				[y * cub->resolution_x + x] >> 8;
			save->bmp[save->index++] = cub->screen
				[y * cub->resolution_x + x] >> 16;
			x++;
		}
		x = 0;
		while (x < (4 - (cub->resolution_x * 3) % 4) % 4)
		{
			save->bmp[save->index++] = 0;
			x++;
		}
		y--;
	}
}

int			ft_save(t_cub3d *cub, char *name)
{
	int			fd;
	t_save		save;

	ft_init_bmp(&save);
	save.size = 54 + 3 * cub->resolution_x * cub->resolution_y;
	save.bmp = malloc(save.size);
	if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
		return (-1);
	write_file_header(&save);
	write_file_info(cub, &save);
	write_body(cub, &save);
	if (!write(fd, save.bmp, save.size))
		return (-1);
	close(fd);
	return (0);
}
