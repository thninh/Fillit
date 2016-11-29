/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:26:32 by thninh            #+#    #+#             */
/*   Updated: 2016/11/29 11:13:51 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_conf			*open_file(char *file, t_conf *conf)
{
	int			fd;

	if (open(file, O_DIRECTORY) >= 0 || open(file, O_RDONLY) < 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if ((conf = read_file(fd, conf)) == 0)
		return (NULL);
	return (conf);
}

t_conf			*read_file(int fd, t_conf *conf)
{
	char		*buff;
	int			i;
	t_tetris	*tetris;
	int			last;
	int			now;

	i = 0;
	last = -1;
	buff = ft_strnew(21);
	while ((now = read(fd, buff, 21)))
	{
		last = now;
		tetris = create_tetris(buff, i);
		if (tetris == NULL)
			return (NULL);
		conf->nb_piece = i + 1;
		conf->list_tetris[i] = *tetris;
		i++;
	}
	if (last != 20 || now != 0)
		return (NULL);
	return (conf);
}
