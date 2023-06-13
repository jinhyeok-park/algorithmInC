/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:11:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/13 18:08:58by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_start(t_game **game)
{
	srand((unsigned int)time(NULL));
	mlx_hook((*game)->mlx_window, 2, 0, player_direction, game);
	mlx_hook((*game)->mlx_window, 17, 0, close_window, game);
	img_load(game);
	draw_map((*game));
	mlx_loop_hook((*game)->mlx, game_loop, game);
	mlx_loop((*game)->mlx);
}

int		game_loop(t_game **game)
{
    // Handle player input and update player position

    // Move enemy

	//draw enemy at top

	//is_collision check

    // Clear the screen and redraw game elements

    // Check for collisions with the player

    // Update the window display

    // Handle game over or exit conditions
	if ((*game)->is_defeat == 0)
	{
		monster_level((*game)->steps, game);
		if ((*game)->frame == 0)
			player_move_bo(game);
		else if ((*game)->frame == 1000)
			player_move_bo(game);
		if ((*game)->enemy_frame == 0)
			enemy_rand_move(game);
		collision_checker(game);
	}
	else
		is_over(game);
	(*game)->frame++;
	(*game)->enemy_frame++;
	if ((*game)->enemy_frame == 8000)
		(*game)->enemy_frame = 0;
	if ((*game)->frame == 2000)
		(*game)->frame = 0;
	return (0);
}

void	is_over(t_game **game)
{
	draw_img((*game)->player_position[1], \
		(*game)->player_position[0], (*game)->img_black, (*game));
	draw_img((*game)->player_position[1], \
		(*game)->player_position[0], (*game)->img_die, (*game));
	if ((*game)->frame % 100 == 0)
		game_defeat(game);
}

void	monster_level(int steps, t_game **game)
{
	if (steps == 0 && (*game)->enemy_count == 0)
		enemy_random_generation(game);
	else if(steps == 100 && (*game)->enemy_count == 1)
	 	enemy_random_generation(game);
	else if(steps == 200 && (*game)->enemy_count == 2)
		enemy_random_generation(game);
	else if(steps == 300 && (*game)->enemy_count == 3)
		enemy_random_generation(game);
	else if(steps == 400 && (*game)->enemy_count == 4)
		enemy_random_generation(game);
}

int	get_random_number(int range)
{
	return (rand() % range);
}

void	enemy_random_generation(t_game **game)
{
	int	randx;
	int	randy;

	while (1)
	{
		randx = get_random_number((*game)->width);
		randy = get_random_number((*game)->height);
		if ((*game)->map[randy][randx] == '0')
		{
			(*game)->enemy_position[(*game)->enemy_count * 2] = randx;
			(*game)->enemy_position[(*game)->enemy_count * 2 + 1] = randy;
			(*game)->enemy_count++;
			break;
		}
	}
}

void	collision_checker(t_game **game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < (*game)->enemy_count)
	{
		x = (*game)->enemy_position[i * 2];
		y = (*game)->enemy_position[i * 2 + 1];
		if ((*game)->player_position[1] == x  &&
		(*game)->player_position[0] == y)
			(*game)->is_defeat = 1;
	}
}

void	game_defeat(t_game **game)
{
	ft_printf("___________MISSION_FAIL______________\n");
	ft_printf("Your Steps     : %d\n", (*game)->steps);
	ft_printf("Collected Coin : %d\n", (*game)->collected_coin);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
	free_game(game);
	exit(0);
}

void	enemy_rand_move(t_game **game)
{
	int	direction;
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < (*game)->enemy_count)
	{
		printf("this is enemy_count%d\n", (*game)->enemy_count);
		x = (*game)->enemy_position[i * 2];
		y = (*game)->enemy_position[i * 2 + 1];
		direction = get_random_number(4);
		printf("cur i %d\n", i);
		printf("cur direction %d \n", direction);
		background_set(x, y, game);
		if (direction == 0)
			enemy_move_position(x + 1, y, game, i);
		else if (direction == 1)
		 	enemy_move_position(x - 1, y, game, i);
		else if (direction == 2)
			enemy_move_position(x, y + 1, game, i);
		else if (direction == 3)
			enemy_move_position(x, y - 1, game, i);
	}
}

void	background_set(int x, int y, t_game **game)
{
	draw_img(x, y, (*game)->img_black, (*game));
	if ((*game)->map[y][x] == 'C')
		draw_img(x, y, (*game)->img_coin, (*game));
	else if ((*game)->map[y][x] == 'P')
		draw_img(x, y, (*game)->img_black, (*game));
	else if ((*game)->map[y][x] == 'E')
		draw_img(x, y, (*game)->img_portal, (*game));
}

void	enemy_move_position(int x, int y, t_game **game, int enemy_index)
{
	int	i;

	i = -1;
	if ((*game)->map[y][x] != '1')
	{
		(*game)->enemy_position[enemy_index * 2] = x;
		(*game)->enemy_position[enemy_index * 2 + 1] = y;
	}
	draw_img((*game)->enemy_position[enemy_index * 2],\
	(*game)->enemy_position[enemy_index * 2 + 1], (*game)->img_enemy, (*game));
}

void	player_move_bo(t_game **game)
{
	if ((*game)->player_direction == 3)
	{
		to_black((*game)->player_position[0], (*game)->player_position[1], (*game));
		move_position((*game)->player_position[0] - 1, (*game)->player_position[1], game);
	}
	if ((*game)->player_direction == 2)
	{
		to_black((*game)->player_position[0], (*game)->player_position[1], (*game));
		move_position((*game)->player_position[0] + 1, (*game)->player_position[1], game);
	}
	if ((*game)->player_direction == 1)
	{
		to_black((*game)->player_position[0], (*game)->player_position[1], (*game));
		move_position((*game)->player_position[0], (*game)->player_position[1] - 1, game);
	}
	if ((*game)->player_direction == 0)
	{
		to_black((*game)->player_position[0], (*game)->player_position[1], (*game));
		move_position((*game)->player_position[0], (*game)->player_position[1] + 1, game);
	}
}

void	img_load(t_game **game)
{
	int	img_width;
	int	img_height;

	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx, "./textures/wall.xpm",\
	 &img_width, &img_height);
	(*game)->img_portal = mlx_xpm_file_to_image((*game)->mlx, "./textures/portal.xpm",\
	 &img_width, &img_height);
	(*game)->img_coin = mlx_xpm_file_to_image((*game)->mlx, "./textures/coin.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[0] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_right_open.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[1] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_right_half.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[2] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_left_open.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[3] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_left_half.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[4] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_down_open.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[5] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_down_half.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[6] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_up_open.xpm",\
	 &img_width, &img_height);
	(*game)->img_player[7] = mlx_xpm_file_to_image((*game)->mlx, "./textures/pack_up_half.xpm",\
	 &img_width, &img_height);
	(*game)->img_black = mlx_xpm_file_to_image((*game)->mlx, "./textures/black.xpm",\
	 &img_width, &img_height);
	(*game)->img_enemy = mlx_xpm_file_to_image((*game)->mlx, "./textures/enemy.xpm",\
	 &img_width, &img_height);
	(*game)->img_die = mlx_xpm_file_to_image((*game)->mlx, "./textures/die.xpm",\
	 &img_width, &img_height);
}

int	player_direction(int keycode, t_game **game)
{
	if (keycode == 53)
	{
		mlx_destroy_window((*game)->mlx, (*game)->mlx_window);
		free_game(game);
		exit(0);
	}
	if (keycode == 13)
		(*game)->player_direction = 3;
	if (keycode == 1)
		(*game)->player_direction = 2;
	if (keycode == 0)
		(*game)->player_direction = 1;
	if (keycode == 2)
		(*game)->player_direction = 0;
	return (0);
}

void	move_position(int x, int y, t_game **game)
{
	if ((*game)->map[x][y] != '1')
	{
		(*game)->player_position[0] = x;
		(*game)->player_position[1] = y;
		(*game)->steps++;
		steps_display(game);
	}
	if ((*game)->map[x][y] == 'C')
	{
		(*game)->collectable_coin--;
		(*game)->map[x][y] = '0';
	}
	if ((*game)->collectable_coin == 0 && (*game)->map[x][y] == 'E')
	{
		draw_img((*game)->player_position[1], (*game)->player_position[0], (*game)->img_player[0], (*game));
		game_fin(game);
	}
	draw_player_img((*game)->player_direction, (*game));
}

void	steps_display(t_game **game)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = ft_itoa((*game)->steps - 1);
	temp_2 = ft_itoa((*game)->steps);
	mlx_string_put((*game)->mlx, (*game)->mlx_window, \
	((*game)->width / 2  - 3) * 32, ((*game)->height + 1) * 32,
	 0xFFFFFF, "steps : ");
	mlx_string_put((*game)->mlx, (*game)->mlx_window, \
	((*game)->width / 2 ) * 32, ((*game)->height + 1) * 32,
	 0x000000, temp_1);
	mlx_string_put((*game)->mlx, (*game)->mlx_window, \
	((*game)->width / 2 ) * 32, ((*game)->height + 1) * 32,
	 0xFFFFFF, temp_2);
	 free(temp_1);
	 free(temp_2);
}

void	A_star(t_game **game)
{

}

void	draw_player_img(int direction, t_game *game)
{
	if (game->frame == 0)
		draw_img(game->player_position[1], game->player_position[0],\
		 game->img_player[2 * direction], game);
	else if (game->frame == 1000)
			draw_img(game->player_position[1], game->player_position[0],\
			 game->img_player[2 * direction + 1], game);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '1')
				draw_img(j, i, game->img_wall, game);
			if (game->map[i][j] == 'E')
				draw_img(j, i, game->img_portal, game);
			if (game->map[i][j] == 'C')
				draw_img(j, i, game->img_coin, game);
			if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				draw_img(j, i , game->img_black, game);
		}
	}
	draw_img(game->player_position[1], game->player_position[0], game->img_player[1], game);
}
