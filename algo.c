/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:26:55 by thninh            #+#    #+#             */
/*   Updated: 2016/11/26 10:47:32 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			brain_rec(t_conf *conf, t_point *pos, char **grid, int iter)
{
	if (iter == conf->nb_piece)
		return (1);
	if (pos->x < 0)
		return (0);
	if (ft_is_putable(grid, pos, &conf->list_tetris[iter]))
	{
		ft_put_piece(grid, pos, &conf->list_tetris[iter]);
		if (brain_rec(conf, ft_new_point(0, 0), grid, iter + 1))
			return (1);
		ft_clean_grid(grid, conf->list_tetris[iter].name);
	}
	return (brain_rec(conf, ft_give_next_point(pos, grid), grid, iter));
}

void		algo(t_conf *conf)
{
	char	**grid;
	t_point	*pos;

	pos = ft_new_point(0, 0);
	conf->min_size = 2;
	grid = ft_new_grid(conf->min_size);
	while (!(brain_rec(conf, pos, grid, 0)))
	{
		conf->min_size++;
		grid = ft_new_grid(conf->min_size);
	}
	conf->grid = ft_copy_grid(grid, conf->min_size);
}
