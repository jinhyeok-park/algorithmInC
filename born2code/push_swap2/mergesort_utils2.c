/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:29 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/19 19:36:11 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_5(t_list_ps *lista, t_list_ps *listb, int size)
{
	int	i;

	i = five_data(lista, size);
	if (i == 0)
		pb(lista, listb, 1);
	else if (i == 1)
	{
		sa(lista, 1);
		pb(lista, listb, 1);
	}
	else if (i == 2)
	{
		rra(lista, 1);
		pb(lista, listb, 1);
		ra(lista, 1);
	}
	sup_5(lista, listb, size, i);
}

void	sup_5(t_list_ps *lista, t_list_ps *listb, int i, int size)
{
	if (i == 3)
	{
		rra(lista, 1);
		rra(lista, 1);
		pb(lista, listb, 1);
		ra(lista, 1);
		ra(lista, 1);
	}
	else if (i == 4)
	{
		ra(lista, 1);
		sa(lista, 1);
		pb(lista, listb, 1);
		rra(lista, 1);
	}
	merge_4(lista, listb, size);
}

int	five_data(t_list_ps *lista, int size)
{
	int	arr[5];
	int	i;
	
	arr[0] = lista->head->data;
	arr[1] = lista->head->next->data;
	arr[2] = lista->tail->data;
	arr[3] = lista->tail->prev->data;
	arr[4] = lista->head->next->next->data;
	i = four_data(lista, size);
	if (size > 0 && arr[i] < arr[4])
		return (4);
	else if (size < 0 && arr[i] > arr[4])
		return (4);
	return (i);
}