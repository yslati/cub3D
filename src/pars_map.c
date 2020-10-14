/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:56:33 by yslati            #+#    #+#             */
/*   Updated: 2020/02/22 16:18:49 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int			check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int					ft_parsing_map(int fd, char buff[3], t_cub3d *cub)
{
	char	*tmp_map;
	int		check;
	char	*line;

	tmp_map = ft_strdup(buff);
	check = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp_map = ft_strjoin(tmp_map, line);
		if (line[0] == '1')
			check = 1;
		if (!ft_strcmp(line, "") && check == 1)
			return (-1);
		tmp_map = ft_strjoin(tmp_map, "\n");
		free(line);
		if (check_line(line))
			check = 0;
	}
	tmp_map = ft_strjoin(tmp_map, line);
	ft_bzero(line, ft_strlen(line));
	free(line);
	cub->map = ft_split(tmp_map, '\n');
	if (ft_check_map_size(cub, 1) == -1 || ft_check_board_map(cub) == -1)
		return (-1);
	return (1);
}
