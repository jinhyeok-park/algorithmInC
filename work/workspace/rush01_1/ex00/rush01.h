/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:04:31 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/22 19:36:30 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include<unistd.h>
# include<stdlib.h>

// make base.c
int		**ft_make_base(int *str);

int		ft_check(int **base, int **map, int row, int col);
void	ft_print_map(int **map);

int		ft_skyscraper(int *base);
int		ft_duplicate(int**base, int **map, int row, int col);
int		ft_row(int **map, int row, int col);
int		ft_col(int **map, int row, int col);
int		ft_direction_up(int **base, int **map, int col);
int		ft_up(int **map, int row_i, int col, int nope);
int		ft_direction_down(int **base, int **map, int col);
int		ft_down(int **map, int row_i, int col, int nope);
int		ft_direction_left(int **base, int **map, int row);
int		ft_left(int **map, int row_i, int row, int nope);
int		ft_direction_right(int **base, int **map, int row);
int		ft_right(int **map, int row_i, int row, int nope);

void	ft_free(int **map, int **base);

#endif
