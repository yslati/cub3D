/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:23:14 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/22 16:18:53 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_find_line(char *str)
{
	int		i;

	i = -1;
	while (str[++i] && str[i] != '\n')
		;
	return (i);
}

int		ft_handle_err(char **line, char *s, char *buff, int r)
{
	if (r == -1)
	{
		if (*line)
			free(*line);
		if (s)
			free(s);
		if (buff)
			free(buff);
	}
	return (r);
}

char	*ft_strnew(char *str, char *dup)
{
	if (str)
		free(str);
	str = dup;
	return (str);
}

int		ft_check_static(char **s, char **line)
{
	int		i;
	char	*tmp;

	if (*s)
	{
		if (ft_strchr(*s, '\n'))
		{
			i = ft_find_line(*s);
			*line = ft_strnew(*line, ft_substr(*s, 0, i));
			*s = ft_strnew(*s, ft_strdup(*s + i + 1));
			if (!*s || !(*line))
				return (ft_handle_err(line, *s, NULL, -1));
			return (1);
		}
		else if (ft_strlen(*s))
		{
			if (!(tmp = (*line) ? ft_strjoin(*line, *s) : ft_strdup(*s)))
				return (ft_handle_err(line, *s, NULL, -1));
			*s = ft_strnew(*s, NULL);
			*line = ft_strnew(*line, tmp);
			return (0);
		}
	}
	free(*s);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *save;
	char		*buff;
	char		*tmp;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
	!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*line = ft_strdup("");
	while ((r = read(fd, buff, BUFFER_SIZE)))
	{
		if (r == -1)
			return (ft_handle_err(line, NULL, buff, -1));
		buff[r] = '\0';
		if (!(tmp = (save) ? ft_strjoin(save, buff) : ft_strdup(buff)))
			return (ft_handle_err(NULL, save, buff, -1));
		save = ft_strnew(save, tmp);
		free(buff);
		if (ft_strchr(save, '\n'))
			break ;
		if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (ft_handle_err(NULL, save, buff, -1));
	}
	(r == 0) ? free(buff) : 0;
	return (ft_check_static(&save, line));
}
