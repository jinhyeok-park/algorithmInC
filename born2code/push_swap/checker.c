/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:20 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/23 09:25:30 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list_ps	*list;
	int			len;

	len = av_count(ac, av);
	if (!check_input(ac, av) || (len == 1 && ac > len + 1))
	{
		error_msg();
		return (0);
	}
	if (ac < 2 || len < 2)
		return (0);
	list = make_list(ac, av, len);
	if (!list)
		return (0);
	if (issorting(list))
		exit(0);
	get_next_start(list);
}

void	get_next_start(t_list_ps *lista)
{
	t_list_ps	*listb;
	char		*temp;

	listb = create_list();
	if (!listb)
		exit(0);
	while (1)
	{
		temp = get_next_line(0);
		if (temp == 0)
		{
			check_sort(lista, listb);
			exit(0);
		}
		do_command(temp, lista, listb);
	}
}

void	check_sort(t_list_ps *lista, t_list_ps *listb)
{
	if (issorting(lista) && listb->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	do_command(char *temp, t_list_ps *lista, t_list_ps *listb)
{
	if (ft_strcmp(temp, "sa"))
	{
		sa(lista, 0);
		return ;
	}
	else if (ft_strcmp(temp, "sb"))
	{
		sb(listb, 0);
		return ;
	}
	else if (ft_strcmp(temp, "ss"))
	{
		sa(lista, 0);
		sb(listb, 0);
		return ;
	}
	else if (ft_strcmp(temp, "pa"))
	{
		pa(lista, listb, 0);
		return ;
	}
	do_command_2(temp, lista, listb);
}

void	do_command_2(char *temp, t_list_ps *lista, t_list_ps *listb)
{
	if (ft_strcmp(temp, "pb"))
		pb(lista, listb, 0);
	else if (ft_strcmp(temp, "ra"))
		ra(lista, 0);
	else if (ft_strcmp(temp, "rb"))
		rb(listb, 0);
	else if (ft_strcmp(temp, "rr"))
	{
		ra(lista, 0);
		rb(listb, 0);
	}
	else if (ft_strcmp(temp, "rra"))
		rra(lista, 0);
	else if (ft_strcmp(temp, "rrb"))
		rrb(listb, 0);
	else if (ft_strcmp(temp, "rrr"))
	{
		rra(lista, 0);
		rrb(listb, 0);
	}
	else
	{
		error_msg();
		exit(1);
	}
}
