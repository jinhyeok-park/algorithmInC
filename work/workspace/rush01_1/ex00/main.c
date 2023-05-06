/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:32:53 by seungule          #+#    #+#             */
/*   Updated: 2023/01/22 21:12:37 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	char_to_int(int *col_row, char **argv);
int		valid_check(char **argv);
int		valid_check2(int *str);

int	valid_check2(int *str)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (str[i] + str[i + 4] > 5)
			return (0);
		if (str[i + 8] + str[i + 12] > 5)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	col_row[16];
	int	valid;

	valid = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	valid = valid_check(argv);
	if (valid)
		char_to_int(col_row, argv);
	valid = valid_check2(col_row);
	if (!valid)
	{	
		write(1, "Error\n", 6);
		return (0);
	}
	ft_skyscraper(col_row);
}

int	valid_check(char **argv)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (argv[1][check])
		check++;
	if (check != 31)
		return (0);
	while (argv[1][i])
	{
		if (i % 2 == 0 && (argv[1][i] < '0' || argv[1][i] > '4'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	char_to_int(int *col_row, char **argv)
{
	int	argv_i;
	int	col_row_i;

	argv_i = 0;
	col_row_i = 0;
	while (argv[1][argv_i])
	{
		if (argv_i % 2 == 0)
		{
			col_row[col_row_i] = argv[1][argv_i] - '0';
			col_row_i++;
		}
		argv_i++;
	}
}
