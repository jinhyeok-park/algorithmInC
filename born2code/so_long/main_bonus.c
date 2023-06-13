/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:37:49 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/13 12:57:13 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int main(int ac, char **av)
{
	t_game	*game;
	char	**map;

	if (ac != 2)
	{
		error_msg(8);
		exit(1);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	map_init_size(&game);
	map = map_checker(av, &game);
	if (!map)
	{
		free_game(&game);
		return (0);
	}
	map_init1(&game);
	game_start(&game);
	return (0);
}