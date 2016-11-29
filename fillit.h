/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:26:04 by thninh            #+#    #+#             */
/*   Updated: 2016/11/29 11:14:09 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetris
{
	char		name;
	t_point		coord[4];
}				t_tetris;

typedef struct	s_conf
{
	char		**grid;
	int			min_size;
	char		nb_piece;
	t_tetris	list_tetris[26];
}				t_conf;

t_conf			*open_file(char *file, t_conf *conf);
t_conf			*read_file(int fd, t_conf *conf);
void			filit(int *argc, char **argv);
t_tetris		*create_tetris(char *str, char name);
void			create_tetris_coord(t_tetris *tetris, int nb, int i);
t_tetris		*check_tetris(t_tetris *tetris);
char			check_form(t_tetris *tetris);
t_tetris		*init_tetris(char name);
t_tetris		*check_order(t_tetris *tetris);
t_conf			*init_conf(void);
void			ft_print_grid(char **tab);
char			**ft_new_grid(int nb_piece);
void			ft_del_grid(char ***grid);
void			ft_clean_grid(char **grid, char letter);
void			ft_put_piece(char **grid, t_point *start, t_tetris *piece);
t_point			*ft_new_point(int x, int y);
int				ft_is_putable(char **grid, t_point *start, t_tetris *piece);
char			**ft_copy_grid(char **grid, int len);
t_point			*ft_give_next_point(t_point *start, char **grid);
char			ft_grid_isfull(char **grid);
int				brain_rec(t_conf *conf, t_point *pos, char **grid, int iter);
void			algo(t_conf *config);

#endif
