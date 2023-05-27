/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:15:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 21:45:14 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list_ps *lista)
{
	t_list_ps	*listb;

	listb = create_list();
	if (lista->size < 6)
		short_sorting(lista, listb);
	else
		merge_sort(lista, listb);
	free_list(lista);
	free_list(listb);
}

void	last_to_a(t_list_ps *lista, t_list_ps *listb)
{
	int	size;

	size = listb->size;
	while (size--)
	{
		rrb(listb, 1);
		pa(lista, listb, 1);
	}
}

void	one_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->size == 1)
	{
		pb(lista, listb, 1);
		arr[2] -= 1;
		return ;
	}
	rra(lista, 1);
	pb(lista, listb, 1);
	arr[2] -= 1;
}

void	one(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (listb->size == 1)
	{
		pa(lista, listb, 1);
		arr[2] -= 1;
		return ;
	}
	rrb(listb, 1);
	pa(lista, listb, 1);
	arr[2] -= 1;
}
