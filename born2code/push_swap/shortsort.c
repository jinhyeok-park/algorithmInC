/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:11:24 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/18 20:15:20 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sorting(t_list_ps *lista, t_list_ps *listb)
{
	if (lista->size == 2)
		sa(lista, 1);
	else if (lista->size == 3)
		sorting_3(lista);
	else if (lista->size == 4)
		sorting_4(lista, listb);
	else
		sorting_5(lista, listb);
}

void	sorting_5(t_list_ps *lista, t_list_ps *listb)
{
	push_minval_to_(lista, listb);
	sorting_4(lista, listb);
	pa(lista, listb, 1);
}

void	sorting_4(t_list_ps *lista, t_list_ps *listb)
{
	push_minval_to_(lista, listb);
	sorting_3(lista);
	pa(lista, listb, 1);
}

void	sorting_3(t_list_ps *list)
{
	int	index;

	index = index_changer(list);
	if (index == 132)
	{
		sa(list, 1);
		ra(list, 1);
	}
	else if (index == 213)
		sa(list, 1);
	else if (index == 231)
		rra(list, 1);
	else if (index == 321)
	{
		sa(list, 1);
		rra(list, 1);
	}
	else if (index == 312)
		ra(list, 1);
}
