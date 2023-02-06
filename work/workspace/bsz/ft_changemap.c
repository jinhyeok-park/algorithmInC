/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroh <sroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:49:00 by sroh              #+#    #+#             */
/*   Updated: 2023/02/01 18:36:24 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_map	*ft_change_map(t_map *smap)
{
	int	i;
	int	j;
	int	rev_i;
	int	rev_j;

	i = 0;
	while (i < smap->row_size)
	{
		j = 0;
		while (j < smap->col_size)
		{
			rev_i = smap->row_size - 1 - i;
			rev_j = smap->col_size - 1 - j;
			if (smap->c_map[i][j] == smap->charmem[1])
				smap->map[rev_i][rev_j] = 0;
			j++;
		}
		i++;
	}
	return (smap);
}

t_map	*ft_change_one(t_map *smap)
{
	int	i;
	int	j;

	ft_change_map(smap);
	i = 0;
	while (i < smap->row_size)
	{
		j = 0;
		while (j < smap->col_size)
		{
			if (i == 0 || j == 0)
			{
				if (smap->map[i][j] == -1)
					smap->map[i][j] = 1;
			}
			j++;
		}
		i++;
	}
	return (smap);
}

t_map	*ft_change_c_map(t_map *smap, int *save)
{
	int	i;
	int	j;

	i = save[1];
	while (i < save[1] + save[0])
	{
		j = save[2];
		while (j < save[2] + save[0])
		{
			smap->c_map[i][j] = smap->charmem[2];
			j++;
		}
		i++;
	}
	return (smap);
}
