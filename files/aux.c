/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtovey <vtovey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 12:38:35 by vtovey            #+#    #+#             */
/*   Updated: 2016/07/27 23:34:56 by vtovey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		get_demin_value(int left, int topleft, int top)
{
	if (topleft < left && topleft < top)
		return (++topleft);
	if (top <= left)
		return (++top);
	return (++left);
}

int		ft_atoin(char *str, int i)
{
	int nb;
	int j;

	j = 0;
	nb = 0;
	while (j <= i - 3)
	{
		nb = nb * 10 + str[j] - '0';
		if (nb < 0)
			return (-1);
		j++;
	}
	if (nb < 0)
		return (-1);
	return (nb);
}

int		ft_check_first_line(char *tmp, int i)
{
	int j;

	j = i;
	if (tmp[j] == tmp[j - 1] || tmp[j] == tmp[j - 2]
		|| tmp[j - 1] == tmp[j - 2])
		return (-1);
	while (j > i - 3)
	{
		if (tmp[j] < 32 || tmp[j] == 127)
			return (-1);
		j--;
	}
	while (j >= 0)
	{
		if (tmp[j] > '9' || tmp[j] < '0')
			return (-1);
		j--;
	}
	return (0);
}

t_map	ft_get_stdin(void)
{
	t_map	map;
	char	buf[1];

	map.fd = open("./tmp/coucou", O_RDWR | O_TRUNC);
	if (map.fd == -1)
		return (map);
	while ((read(0, buf, 1)) > 0)
	{
		write(map.fd, buf, 1);
	}
	return (map);
}

void	ft_allin(void)
{
	t_map	map;
	t_bsq	bsq;
	int		**demin;

	map = ft_get_stdin();
	map = ft_get_map("./tmp/coucou");
	if (map.valid == 0)
		return ;
	map = get_map_wid(map);
	demin = fill_line_one(map, "./tmp/coucou");
	if (demin == 0)
		return ;
	bsq = algo_demin(map, demin);
	if (bsq.valid == 0)
		return ;
	display_bsq(map, bsq, "./tmp/coucou");
}
