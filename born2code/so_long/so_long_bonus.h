/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:46:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/06/07 15:50:16y jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include "./mlx/mlx.h"
#include "./ft_printf/ft_printf.h"
#include <time.h>

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	int		total_len;
	int		steps;
	int		collectable_coin;
	int		collected_coin;
	int		is_accessible;
	int		accessible_coin;
	int		player_direction;
	int		frame;
	int		enemy_count;
	int		enemy_frame;
	int		is_defeat;
	void	*mlx;
	void	*mlx_window;
	int		player_position[2];
	int     portal_position[2];
	int     enemy_position[10];
	void	*img_wall;
	void	*img_black;
	void	*img_coin;
	void	*img_portal;
	void	*img_player[8];
	void	*img_enemy;
	void	*img_die;
}   t_game;

//map_checker.c
int		count_coin(t_game **game, char **map);
int		is_surrounded(t_game **game, char **map);
int		line_size_check(t_game **game, char **map);
int		get_portal_pos(t_game **game, char **map);
int		get_player_pos(t_game **game, char **map);
//map_checker2.c
char	**map_checker(char **av, t_game **game);
char	**map_checker_2(char **map, t_game **game);
char	**map_checker_3(char **map, t_game **game);
void	dfs(int	x, int y, char **map, char **visited, t_game **game);
int		portal_accessible(char **map, t_game **game);
//map_checker3.c
int		five_char(char c);
int		check_five_char(char **map);

//so_long_utils.c
void	draw_img(int y, int x, void *img, t_game *game);
char	*ft_strjoin_custom(char *s1, char *s2);
void	game_fin(t_game **game);
int		close_window(t_game **game);
void	to_black(int x, int y, t_game *game);

//so_long.c
void	game_start(t_game **game);
void	img_load(t_game **game);
int		player_move(int keycode, t_game **game);
void	move_position(int x, int y, t_game **game);
void	draw_map(t_game *game);

//init.c
void	map_init1(t_game **game);
void	map_init_size(t_game **game);
void	init_map(char **map, int height, int width);

//free.c
void	free_game(t_game **game);
void	free_map(char **map, int height);

//error.c
void	error_msg(int num);

void	user_move(t_game *game);
void	to_black(int x, int y, t_game *game);


char    *ft_cat_remove_newline(char *s1 , char *s2);
int     make_map(t_game **game);
int     map_init(t_game **game, char *map_path);
char	*ft_strdup(const char *src);
int     map_maker(t_game *game);
int     get_player_posi(t_game **game);
int     get_portal_posi(t_game **game);


int	player_direction(int keycode, t_game **game);
void	player_move_bo(t_game **game);
int		game_loop(t_game **game);
void	fram_move(int x, int y, void **sprite_img, int sprite_count, t_game *game);
void	draw_player_img(int direction, t_game *game);
//line checker

//enemy
void	enemy_random_generation(t_game **game);
int		get_random_number(int range);
void	enemy_move_position(int x, int y, t_game **game, int enemy_index);
void	enemy_rand_move(t_game **game);
void	background_set(int x, int y, t_game **game);
void	monster_level(int steps, t_game **game);
void	collision_checker(t_game **game);
void	game_defeat(t_game **game);
void	ft_sleep(int count);
void	is_over(t_game **game);
void	steps_display(t_game **game);
#endif