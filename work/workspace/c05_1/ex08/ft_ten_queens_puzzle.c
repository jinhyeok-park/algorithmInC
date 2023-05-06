/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:53 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/20 20:55:55 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_print(int *arr)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = arr[i++] + '0';
		write(1, &temp, 1);
	}
	write(1, "\n", 1);
}

int	ft_ispromising(int *arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (arr[i] == arr[row] || ft_abs(arr[i] - arr[row]) == ft_abs(i - row))
			return (0);
		i++;
	}
	return (1);
}

void	ft_nqueens(int *arr, int N, int row, int *count)
{
	int	column;

	column = 0;
	if (ft_ispromising(arr, row))
	{
		if (row == N - 1)
		{
			*count += 1;
			ft_print(arr);
		}
		else
		{
			while (column < N)
			{
				arr[row + 1] = column;
				ft_nqueens(arr, N, row + 1, count);
				column++;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < 10)
		arr[i++] = -1;
	ft_nqueens(arr, 10, -1, &count);
	return (count);
}
