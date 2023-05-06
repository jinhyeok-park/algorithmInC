/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:16:46 by seycho            #+#    #+#             */
/*   Updated: 2022/09/05 19:20:05 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_colup(t_input_data *data, int x, int y, int height)
{
	int	i;
	int	max;
	int	count;
	int	**grid;

	i = 1;
	count = 1;
	grid = data->board;
	max = grid[0][y];
	while (i <= x)
	{
		if (grid[i][y] > max)
		{
			max = grid[i][y];
			count++;
		}
		if ((grid[i][y] == data->n && count != data->input[0][y])
				|| grid[i - 1][y] == height)
			return (0);
		i++;
	}
	if (x == data->n - 1 && !check_coldown(data, y))
		return (0);
	return (1);
}

int	check_coldown(t_input_data *data, int y)
{
	int	i;
	int	max;
	int	count;
	int	**grid;

	i = data->n - 1;
	count = 0;
	grid = data->board;
	max = 0;
	while (i >= 0)
	{
		if (grid[i][y] > max)
		{
			max = grid[i][y];
			count++;
		}
		if (count > data->input[1][y])
			return (0);
		i--;
	}
	if (count != data->input[1][y])
		return (0);
	return (1);
}

int	check_rowleft(t_input_data *data, int x, int y, int height)
{
	int	i;
	int	max;
	int	count;
	int	**grid;

	i = 1;
	count = 1;
	grid = data->board;
	max = grid[x][0];
	while (i <= y)
	{
		if (grid[x][i] > max)
		{
			max = grid[x][i];
			count++;
		}
		if ((grid[x][i] == data->n && count != data->input[2][x])
				|| grid[x][i - 1] == height)
			return (0);
		i++;
	}
	if (y == data->n - 1 && !check_rowright(data, x))
		return (0);
	return (1);
}

int	check_rowright(t_input_data *data, int x)
{
	int	i;
	int	max;
	int	count;
	int	**grid;

	i = data->n - 1;
	count = 0;
	grid = data->board;
	max = 0;
	while (i >= 0)
	{
		if (grid[x][i] > max)
		{
			max = grid[x][i];
			count++;
		}
		if (count > data->input[3][x])
			return (0);
		i--;
	}
	if (count != data->input[3][x])
		return (0);
	return (1);
}

int	check_board(t_input_data *data, int x, int y, int height)
{
	data->board[x][y] = height;
	if (!check_colup(data, x, y, height))
	{
		data->board[x][y] = 0;
		return (0);
	}
	if (!(check_rowleft(data, x, y, height)))
	{
		data->board[x][y] = 0;
		return (0);
	}
	return (1);
}
