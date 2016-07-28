/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydecamps <ydecamps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 12:59:27 by ydecamps          #+#    #+#             */
/*   Updated: 2016/07/27 23:19:35 by ydecamps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	algo_demin(t_map map, int **demin)
{
	char			this[2];
	static t_bsq	bsq = {.x = 0, .siz = 0, .y = 0, .sx = 0, .sy = 0, .sw = 0};

	bsq.valid = 1;
	while (bsq.x < map.wid)
		demin[1][bsq.x++] = 0;
	bsq.x = 0;
	while (read(map.fd, this, 1))
	{
		bsq = algo_demin_part(map, bsq, &demin, this);
		if (this[0] != map.e && this[0] != '\n' && this[0] != map.o)
			return (ft_tbsq_error(map));
		++bsq.x;
		if (this[0] == '\n')
		{
			if (bsq.x != map.wid)
				return (ft_tbsq_error(map));
			bsq.x = 0;
			++bsq.y;
			bsq.sw = 1 - bsq.sw;
		}
	}
	if (bsq.y != map.hei)
		return (ft_tbsq_error(map));
	return (bsq);
}

t_bsq	algo_demin_part(t_map map, t_bsq bsq, int ***demin, char this[2])
{
	if (this[0] == map.o)
		(*demin)[bsq.sw][bsq.x] = 0;
	else if (this[0] != '\n')
	{
		if (bsq.x == 0)
			(*demin)[bsq.sw][bsq.x] = 1;
		else
			(*demin)[bsq.sw][bsq.x] =
			get_demin_value((*demin)[bsq.sw][bsq.x - 1],
			(*demin)[1 - bsq.sw][bsq.x - 1], (*demin)[1 - bsq.sw][bsq.x]);
		if (bsq.siz < (*demin)[bsq.sw][bsq.x])
		{
			bsq.siz = (*demin)[bsq.sw][bsq.x];
			bsq.sx = bsq.x;
			bsq.sy = bsq.y;
		}
	}
	return (bsq);
}

void	display_line(t_map map, t_bsq bsq, char buf[map.wid])
{
	int j;

	j = -1;
	while (++j < map.wid)
	{
		if (j <= bsq.sx - bsq.siz || j > bsq.sx)
			write(1, &buf[j], 1);
		else
			write(1, &map.f, 1);
	}
}

void	display_bsq(t_map map, t_bsq bsq, char *file)
{
	char	buf[2];

	close(map.fd);
	map.fd = open(file, O_RDWR);
	buf[0] = '0';
	while (buf[0] != '\n')
		read(map.fd, buf, 1);
	display_bsq_next(map, bsq);
	close(map.fd);
}

void	display_bsq_next(t_map map, t_bsq bsq)
{
	static int	i = -1;
	int			j;
	char		buf[map.wid];

	while (++i < map.hei)
	{
		read(map.fd, buf, map.wid);
		if (i <= bsq.sy - bsq.siz)
			write(1, buf, map.wid);
		else if (i <= bsq.sy)
		{
			j = -1;
			while (++j < map.wid)
			{
				if (j <= bsq.sx - bsq.siz || j > bsq.sx)
					write(1, &buf[j], 1);
				else
					write(1, &map.f, 1);
			}
		}
		else
			write(1, buf, map.wid);
	}
}
