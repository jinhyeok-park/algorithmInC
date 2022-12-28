/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:32:12 by seycho            #+#    #+#             */
/*   Updated: 2022/09/04 19:50:47 by seminkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_promising(t_input_data *data, int x, int y, int height)
{
	if (x == 0 && !check_if_possible(data->input[0][y], height, data->n))
		return (0);
	if (y == 0 && !check_if_possible(data->input[2][x], height, data->n))
		return (0);
	if (!check_board(data, x, y, height))
		return (0);
	return (1);
}

int	check_if_possible(int view, int height, int n)
{
	if (height > (n - view) + 1)
		return (0);
	return (1);
}

int	rush(t_input_data *data, int x, int y)
{
	int	i;

	i = 1;
	if (y == data->n && x == data->n - 1)
		return (1);
	if (y == data->n)
	{
		x++;
		y = 0;
	}
	while (i <= data->n)
	{
		if (is_promising(data, x, y, i))
		{
			data->board[x][y] = i;
			if (rush(data, x, y + 1))
				return (1);
		}
		data->board[x][y] = 0;
		i++;
	}
	return (0);
}
