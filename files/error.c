/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtovey <vtovey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:48:30 by vtovey            #+#    #+#             */
/*   Updated: 2016/07/27 23:20:01 by ydecamps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_map_error(t_map map)
{
	close(map.fd);
	write(2, "map error\n", 10);
}

t_map	ft_tmap_error(t_map map)
{
	ft_map_error(map);
	map.valid = 0;
	return (map);
}

t_bsq	ft_tbsq_error(t_map map)
{
	t_bsq bsq;

	ft_map_error(map);
	bsq.valid = 0;
	return (bsq);
}
