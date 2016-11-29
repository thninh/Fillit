/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:25:53 by thninh            #+#    #+#             */
/*   Updated: 2016/11/29 11:17:43 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris			*init_tetris(char name)
{
	t_tetris		*tetris;
	t_point			*coord;
	int				i;

	i = -1;
	tetris = (t_tetris*)malloc(sizeof(t_tetris));
	tetris->name = name + 65;
	while (++i < 4)
	{
		coord = (t_point*)malloc(sizeof(*coord));
		coord->x = -1;
		coord->y = -1;
		tetris->coord[i] = *coord;
	}
	return (tetris);
}

t_tetris			*create_tetris(char *str, char name)
{
	t_tetris		*tetris;
	int				i;
	int				nb;

	i = -1;
	nb = -1;
	tetris = init_tetris(name);
	while (++i < 20)
	{
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (NULL);
		if (str[i] == '.' || str[i] == '\n')
			;
		else if (str[i] == '#' && ++nb < 4)
			create_tetris_coord(tetris, nb, i);
		else
			return (NULL);
	}
	if (name != 0 && str[i] != '\n')
		return (NULL);
	return (check_tetris(tetris));
}

void				create_tetris_coord(t_tetris *tetris, int nb, int i)
{
	t_point			point;

	point = *ft_new_point(i % 5, i / 5);
	tetris->coord[nb] = point;
}

t_conf				*init_conf(void)
{
	t_conf			*conf;

	conf = (t_conf*)malloc(sizeof(*conf));
	return (conf);
}
