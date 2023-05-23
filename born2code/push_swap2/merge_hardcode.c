/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_hardcode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:30:06 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:43:44 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_4(t_list_ps *lista, t_list_ps *listb, int size)
{
	int	i;

	i = four_data(lista, size);
	if (i == 0)
	{
		pb(lista, listb, 1);
		rra(lista, 1);
	}
	else if (i == 1)
	{
		sa(lista, 1);
		pb(lista, listb, 1);
		rra(lista, 1);
	}
	merge_4_sup(lista, listb, i, size);
}

void	merge_4_sup(t_list_ps *lista, t_list_ps *listb, int i, int size)
{
	if (i == 2)
	{
		rra(lista, 1);
		pb(lista, listb, 1);
	}
	else if (i == 3)
	{
		rra(lista, 1);
		rra(lista, 1);
		pb(lista, listb, 1);
		ra(lista, 1);
	}
	merge_3(lista, listb, size);
}

void	merge_3(t_list_ps *lista, t_list_ps *listb, int size)
{
	int	i;

	i = three_data(lista, size);
	if (i == 0)
		pb(lista, listb, 1);
	else if (i == 1)
	{
		sa(lista, 1);
		pb(lista, listb, 1);
	}
	else
	{
		rra(lista, 1);
		pb(lista, listb, 1);
		ra(lista, 1);
	}
	merge_2(lista, listb, size);
}

void	merge_2(t_list_ps *lista, t_list_ps *listb, int size)
{
	if ((size > 0 && lista->head->data > lista->tail->data) \
	|| (size < 0 && lista->head->data < lista->tail->data))
	{
		pb(lista, listb, 1);
		rra(lista, 1);
	}
	else
	{
		rra(lista, 1);
		pb(lista, listb, 1);
	}
	pb(lista, listb, 1);
}
