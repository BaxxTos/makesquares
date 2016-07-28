/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtovey <vtovey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 19:34:42 by vtovey            #+#    #+#             */
/*   Updated: 2016/07/27 23:18:01 by ydecamps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct	s_map
{
	int			fd;
	int			hei;
	int			wid;
	char		e;
	char		o;
	char		f;
	int			valid;
}				t_map;

typedef struct	s_bsq
{
	int			x;
	int			y;
	int			sx;
	int			sy;
	int			siz;
	int			valid;
	int			sw;
}				t_bsq;

/*
** algo.c
*/
t_bsq			algo_demin(t_map map, int **demin);
void			display_bsq(t_map map, t_bsq bsq, char *file);
void			display_line(t_map map, t_bsq bsq, char buf[map.wid]);
void			display_bsq_next(t_map map, t_bsq bsq);
t_bsq			algo_demin_part(t_map map, t_bsq bsq, int ***demin,
				char this[2]);

/*
** aux.c
*/
int				ft_atoin(char *str, int i);
int				ft_check_first_line(char *tmp, int i);
t_map			ft_get_stdin(void);
void			ft_allin(void);
int				get_demin_value(int a, int b, int c);

/*
** main.c
*/
void			ft_allout(int argc, char **argv);
t_map			ft_get_map(char *wmap);
t_map			get_map_wid(t_map map);
int				**fill_line_one(t_map map, char *wmap);

/*
** error.c
*/
void			ft_map_error(t_map map);
t_map			ft_tmap_error(t_map map);
t_bsq			ft_tbsq_error(t_map map);

#endif
