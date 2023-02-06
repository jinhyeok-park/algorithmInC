/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroh <sroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:47:23 by sroh              #+#    #+#             */
/*   Updated: 2023/02/01 18:21:02 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_min(t_map *smap, int row, int col)
{
	int	min;
	int	result;

	min = smap->map[row - 1][col - 1];
	result = 1;
	if (min > smap->map[row - 1][col])
	{
		min = smap->map[row - 1][col];
		result = 2;
	}
	if (min > smap->map[row][col - 1])
	{
		min = smap->map[row][col - 1];
		result = 3;
	}
	return (result);
}

void	ft_make_square(t_map *smap)
{
	int	row;
	int	col;

	row = 0;
	while (row < smap->row_size)
	{
		col = 0;
		while (col < smap->col_size)
		{
			if (smap->map[row][col] == -1)
			{
				if (ft_check_min(smap, row, col) == 1)
					smap->map[row][col] = smap->map[row - 1][col - 1] + 1;
				else if (ft_check_min(smap, row, col) == 2)
					smap->map[row][col] = smap->map[row - 1][col] + 1;
				else
					smap->map[row][col] = smap->map[row][col - 1] + 1;
			}
			col++;
		}
		row++;
	}
}

void	ft_check_max(t_map *smap, int *save)
{
	int	row;
	int	col;
	int	max;

	max = 0;
	row = 0;
	while (row < smap->row_size)
	{
		col = 0;
		while (col < smap->col_size)
		{
			if (max <= smap->map[row][col])
			{
				max = smap->map[row][col];
				save[0] = max;
				save[1] = smap->row_size -1 - row;
				save[2] = smap->col_size -1 - col;
			}
			col++;
		}
		row++;
	}
}

int	*ft_save_maxpoint(t_map *smap)
{
	int	*save;

	save = (int *)malloc(sizeof(int) * 3);
	ft_make_square(smap);
	ft_check_max(smap, save);
	return (save);
}
