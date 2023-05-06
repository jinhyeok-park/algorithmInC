/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:59:36 by seycho            #+#    #+#             */
/*   Updated: 2022/09/04 21:25:18 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_board(t_input_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->board = (int **)malloc(sizeof(int *) * (data->n));
	if (!(data->board))
		return ;
	while (i < data->n)
	{
		j = 0;
		data->board[i] = (int *)malloc(sizeof(int) * (data->n));
		if (!(data->board[i]))
		{
			free_all(data);
			return ;
		}
		while (j < data->n)
			data->board[i][j++] = 0;
		i++;
	}
}

void	free_all(t_input_data *data)
{
	int	i;

	i = 0;
	while (i < data->n)
	{
		free(data->board[i]);
		i++;
	}
	free(data->board);
	i = 0;
	while (i < 4)
	{
		free(data->input[i]);
		i++;
	}
	free(data->input);
}

void	print_board(int **board, int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = (char)board[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			if (j == n - 1)
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}

int	print_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(2, &msg[i], 1);
		i++;
	}
	return (-1);
}
