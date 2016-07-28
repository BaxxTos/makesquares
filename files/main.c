/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtovey <vtovey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:32:04 by vtovey            #+#    #+#             */
/*   Updated: 2016/07/27 23:19:21 by ydecamps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	ft_get_map(char *file)
{
	t_map		map;
	char		buf[1];
	char		tmp[100];
	static int	i = 0;

	buf[0] = '0';
	map.fd = open(file, O_RDWR);
	if (map.fd == -1)
		return (ft_tmap_error(map));
	while (buf[0] != '\n')
	{
		if ((read(map.fd, buf, 1)) == 0)
			return (ft_tmap_error(map));
		tmp[i] = buf[0];
		i++;
	}
	if (i < 5 || (ft_check_first_line(tmp, i - 2) == -1))
		return (ft_tmap_error(map));
	map.hei = ft_atoin(tmp, i - 2);
	map.e = tmp[i - 4];
	map.o = tmp[i - 3];
	map.f = tmp[i - 2];
	map.wid = 0;
	map.valid = 1;
	return (map);
}

t_map	get_map_wid(t_map map)
{
	char	buf[1];
	int		size;

	buf[0] = '0';
	size = 0;
	read(map.fd, buf, 1);
	while (buf[0] != '\n')
	{
		if ((read(map.fd, buf, 1) == 0))
			return (ft_tmap_error(map));
		size++;
	}
	map.wid = size + 1;
	return (map);
}

int		**fill_line_one(t_map map, char *file)
{
	int		**demin;
	char	buf[map.wid];

	close(map.fd);
	map.fd = open(file, O_RDWR);
	if (map.fd == -1)
		return (0);
	while (buf[0] != '\n')
	{
		read(map.fd, buf, 1);
	}
	demin = (int**)malloc(sizeof(int*) * 3);
	if (demin == 0)
		return (0);
	demin[0] = (int*)malloc(sizeof(int) * (map.wid));
	demin[1] = (int*)malloc(sizeof(int) * (map.wid));
	if (demin[0] == 0 || demin[1] == 0)
		return (0);
	return (demin);
}

void	ft_allout(int argc, char **argv)
{
	t_map		map;
	t_bsq		bsq;
	int			**demin;
	static int	argnb = 0;

	while (++argnb < argc)
	{
		map = ft_get_map(argv[argnb]);
		if (map.valid == 0 || map.hei < 0)
			continue ;
		map = get_map_wid(map);
		if (map.valid == 0 || map.hei < 0)
			continue ;
		demin = fill_line_one(map, argv[argnb]);
		if (demin == 0)
			continue ;
		bsq = algo_demin(map, demin);
		if (bsq.valid == 0)
			continue ;
		display_bsq(map, bsq, argv[argnb]);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_allin();
	}
	else if (argc > 1)
		ft_allout(argc, argv);
	return (0);
}
