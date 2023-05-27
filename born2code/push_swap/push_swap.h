/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:54:09 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/26 15:55:03 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list_ps
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_list_ps;
//push_swap.c
int			sp_nu_checker(int ac, char **av);

//check_input.c
int			check_input(int ac, char **av);
int			check_space(int ac, char **av);
int			av_count(int ac, char **av);
long long	*make_new_av(int ac, char **av);
int			check_dup(long long *new_av, int len);

// check_input_util.c
int			check_isdigit(int ac, char **av);
int			check_self(long long *new_av, long long cur, int idx);
int			check_intmax(long long *temp, int len);
void		freeall(char **s);

//utils.c
void		error_msg(void);
long long	ft_atoll(char *str);

//stack.c
t_list_ps	*make_list(int ac, char **av, int len);

//list_util.c
t_list_ps	*create_list(void);
void		free_list(t_list_ps *list);

//list_util2.c
void		pop_head(t_list_ps *list);
void		pop_tail(t_list_ps *list);
int			push_head(t_list_ps *list, int data);
int			push_tail(t_list_ps *list, int data);
t_node		*create_node(int data);

//command2.c
int			pa(t_list_ps *lista, t_list_ps *listb, int flag);
int			pb(t_list_ps *lista, t_list_ps *listb, int flag);
int			sa(t_list_ps *list, int flag);
int			sb(t_list_ps *list, int flag);

//command.c
int			ra(t_list_ps *list, int flag);
int			rb(t_list_ps *list, int flag);
int			rra(t_list_ps *list, int flag);
int			rrb(t_list_ps *list, int flag);

// sorting.c
void		sorting(t_list_ps *lista);
void		last_to_a(t_list_ps *lista, t_list_ps *listb);
void		one_a(t_list_ps *lista, t_list_ps *listb, int *arr);
void		one(t_list_ps *lista, t_list_ps *listb, int *arr);

//shortsort.c
void		short_sorting(t_list_ps *lista, t_list_ps *listb);
void		sorting_3(t_list_ps *list);
void		sorting_4(t_list_ps *lista, t_list_ps *listb);
void		sorting_5(t_list_ps *lista, t_list_ps *listb);

//shortsort_utils.c
int			index_changer(t_list_ps *list);
void		push_minval_to_(t_list_ps *lista, t_list_ps *listb);
int			val_index(t_list_ps *list, int data);
void		rra_p(t_list_ps *lista, t_list_ps *listb, int data);
void		ra_p(t_list_ps *lista, t_list_ps *listb, int data);

//mergesort.c
void		merge_sort(t_list_ps *lista, t_list_ps *listb);
void		to_b(t_list_ps *lista, t_list_ps *listb, int *sort_size, int dep);
void		sort_all(t_list_ps *lista, t_list_ps *listb, int dep);

//mergesort_utils.c
int			*get_triangle(int depth, int size);
int			get_order(int idx);
void		get_direction(int *sort_size, int dep);

//merge_hardcode.c
void		merge_4(t_list_ps *lista, t_list_ps *listb, int size);
void		merge_4_sup(t_list_ps *lista, t_list_ps *listb, int i, int size);
void		merge_3(t_list_ps *lista, t_list_ps *listb, int size);
void		merge_2(t_list_ps *lista, t_list_ps *listb, int size);

//merge_hardcode_utils.c
int			four_data(t_list_ps *lista, int size);
int			three_data(t_list_ps *lista, int size);

// tri_to_a.c
void		to_a(t_list_ps *lista, t_list_ps *listb, int *sort_size, int dep);
void		make_tri(t_list_ps *lista, t_list_ps *listb, int idx, int dep);
void		make_tri2(t_list_ps *lista, t_list_ps *listb, int *arr);
void		make_tri_up(t_list_ps *lista, t_list_ps *listb, int *arr);
void		make_tri_down(t_list_ps *lista, t_list_ps *listb, int *arr);

//to_a_up.c
void		check_all(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_a(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_b(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_c(t_list_ps *lista, t_list_ps *listb, int *arr);
void		three(t_list_ps *lista, t_list_ps *listb, int *arr);

//to_a_down.c
void		check_all_d(t_list_ps *lista, t_list_ps *listb, int *arr);
void		three_d(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_da(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_db(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_dc(t_list_ps *lista, t_list_ps *listb, int *arr);

//tri_utils.c
int			issorting(t_list_ps *list);
int			find_max(t_list_ps *lista, t_list_ps *listb);
int			ft_pow(int num, int power);
int			depth(int size);
void		make_posit(int *arr);

//tri_utils2.c
int			find_max_intri(t_list_ps *lista, t_list_ps *listb);
int			ft_abs(int abs);
int			find_min_tri(t_list_ps *lista, t_list_ps *listb);
int			find_min_tri_d(t_list_ps *lista, t_list_ps *listb);
int			find_max_intri_a(t_list_ps *lista, t_list_ps *listb);

//tri_to_b.c
void		tob(t_list_ps *lista, t_list_ps *listb, int *sort_size, int dep);
void		make_tri_a(t_list_ps *lista, t_list_ps *listb, int idx, int dep);
void		make_tri2_a(t_list_ps *lista, t_list_ps *listb, int *arr);
void		make_tri_up_a(t_list_ps *lista, t_list_ps *listb, int *arr);
void		make_tri_down_a(t_list_ps *lista, t_list_ps *listb, int *arr);

//to_b_up.c
void		check_all_a(t_list_ps *lista, t_list_ps *listb, int *arr);
void		three_a(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_aa(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_ab(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_ac(t_list_ps *lista, t_list_ps *listb, int *arr);

//to_b_down.c
void		check_all_ad(t_list_ps *lista, t_list_ps *listb, int *arr);
void		three_ad(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_aad(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_abd(t_list_ps *lista, t_list_ps *listb, int *arr);
void		two_acd(t_list_ps *lista, t_list_ps *listb, int *arr);

void		merge_5(t_list_ps *lista, t_list_ps *listb, int size);
void		sup_5(t_list_ps *lista, t_list_ps *listb, int i, int size);
int			five_data(t_list_ps *lista, int size);
//libft
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);

//get_next_line
char		*get_next_line(int fd);
void		do_command(char *temp, t_list_ps *lista, t_list_ps *listb);
int			ft_strcmp(char *s1, char *s2);
void		get_next_start(t_list_ps *lista);
void		check_sort(t_list_ps *lista, t_list_ps *listb);
void		do_command_2(char *temp, t_list_ps *lista, t_list_ps *listb);
void		iserror(char *temp, t_list_ps *lista, t_list_ps *listb);

#endif