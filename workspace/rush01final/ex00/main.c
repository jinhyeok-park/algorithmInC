/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:16:57 by seycho            #+#    #+#             */
/*   Updated: 2022/09/04 21:09:47 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	t_input_data	data;
	int				n;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (argc != 2)
		return (print_error("Error\n"));
	n = get_n(argv[1]);
	if (n == 0 || !(check_input(argv[1], n)))
		return (print_error("Error\n"));
	data.input = parse_input(argv[1], n);
	data.n = n;
	init_board(&data);
	if (!(rush(&data, 0, 0)))
		print_error("Error\n");
	else
		print_board(data.board, data.n);
	free_all(&data);
	return (0);
}
