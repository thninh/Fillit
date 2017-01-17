/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:26:50 by thninh            #+#    #+#             */
/*   Updated: 2016/11/26 10:55:54 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			fillit(int *argc, char **argv)
{
	t_conf		*conf;

	conf = init_conf();
	if (*argc == 2)
	{
		if ((conf = open_file(argv[1], conf)) != NULL)
		{
			algo(conf);
			ft_print_grid(conf->grid);
			return ;
		}
	}
	ft_putstr("error\n");
}

int				main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else
		fillit(&argc, argv);
	return (0);
}
