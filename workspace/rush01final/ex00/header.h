/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:17:26 by seycho            #+#    #+#             */
/*   Updated: 2022/09/06 09:59:01 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	**input;
	int	**board;
	int	n;
}	t_input_data;
/* rush.c */
int		is_promising(t_input_data *data, int x, int y, int height);
int		check_if_possible(int view, int height, int n);
int		rush(t_input_data *data, int x, int y);
/* input.c */
int		**parse_input(char *str, int n);
int		str_len(char *str);
int		is_numeric(char c);
int		get_n(char *str);
int		check_input(char *str, int n);
/* utils.c */
void	init_board(t_input_data *data);
void	print_board(int **board, int n);
int		print_error(char *msg);
void	free_all(t_input_data *data);
/* check.c */
int		check_colup(t_input_data *data, int x, int y, int height);
int		check_coldown(t_input_data *data, int y);
int		check_rowleft(t_input_data *data, int x, int y, int height);
int		check_rowright(t_input_data *data, int x);
int		check_board(t_input_data *data, int x, int y, int height);

#endif
