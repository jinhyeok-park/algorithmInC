/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:54:09 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/12 15:17:48 by jinhyeok         ###   ########.fr       */
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

typedef struct s_list_ps
{
	t_node	*head;
	t_node	*tail;
	int		size;
} t_list_ps;

typedef struct s_tri
{
	int	*direction;
	int	*size_list;
	int size;
} t_tri;

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
t_list_ps	*make_list(int ac, char **av, int len);

//list_util.c
t_list_ps		*create_list(void);
//t_list_ps		*push_head(t_list_ps *list, int data);
//t_node			*create_node(int data);
//void			pop_tail(t_list_ps *list);
void			free_list(t_list_ps *list);

//list_util2.c
void	pop_head(t_list_ps *list);
void	pop_tail(t_list_ps *list);
int		push_head(t_list_ps *list, int data);
int		push_tail(t_list_ps *list, int data);
t_node	*create_node(int data);

int pa(t_list_ps *lista, t_list_ps *listb, int flag);
int pb(t_list_ps *lista, t_list_ps *listb, int flag);
int sa(t_list_ps *list, int flag);
int ra(t_list_ps *list, int flag);
int rra(t_list_ps *list, int flag);
int rrb(t_list_ps *list, int flag);

void	sorting(t_list_ps *lista);
void	short_sorting(t_list_ps *lista, t_list_ps *listb);
void	sorting_3(t_list_ps *list);
//void	sorting_45(t_list_ps *lista, t_list_ps *listb);
void	sorting_4(t_list_ps *lista, t_list_ps *listb);
void	sorting_5(t_list_ps *lista, t_list_ps *listb);
void	push_minval_to_(t_list_ps *lista, t_list_ps *listb);
void	ra_p(t_list_ps *lista, t_list_ps *listb, int data);
void	rra_p(t_list_ps *lista, t_list_ps *listb, int data);
int	val_index(t_list_ps *list, int data);

int		index_changer(t_list_ps *list);
int	issorting(t_list_ps *list);

void	biggest_push_b(t_list_ps *lista, t_list_ps *listb);
void	merge_test(t_list_ps *lista, t_list_ps *listb);
int		find_max(t_list_ps *lista, t_list_ps *listb);

int		get_order(int idx);
void	get_direction(int *sort_size, int dep);
int		ft_pow(int num, int power);
void	merge_sort(t_list_ps *lista, t_list_ps *listb);
int	depth(int size);
#endif