/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:54:09 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/03 16:34:45 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail
} t_list;

//check_input.c
int			check_isdigit(int ac, char **av);
int			check_input(int ac, char **av);
int			check_space(int ac, char **av);
int			av_count(int ac, char **av);
long long	*make_new_av(int ac, char **av);
int			check_dup(long long *new_av, int len);

// check_input_util.c
int			check_self(long long *new_av, long long cur, int idx);
int			check_intmax(long long *temp, int len);

//utils.c
void		error_msg(void);
long long	ft_atoll(char *str);

//stack.c
int			make_list(int ac, char **av);

//list_util.c
t_list		*create_list(void);

#endif