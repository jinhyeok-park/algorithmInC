/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:49:26 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:32:28 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_all_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
		three_a(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] > 0 && arr[2] == 0)
		two_ac(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] == 0 && arr[2] > 0)
		two_ab(lista, listb, arr);
	else if (arr[0] == 0 && arr[1] > 0 && arr[2] > 0)
		two_aa(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] == 0 && arr[2] == 0)
	{
		pb(lista, listb, 1);
		arr[0] -= 1;
	}
	else if (arr[0] == 0 && arr[1] > 0 && arr[2] == 0)
	{
		rrb(listb, 1);
		arr[1] -= 1;
	}
	else if (arr[0] == 0 && arr[1] == 0 && arr[2] > 0)
		one_a(lista, listb, arr);
}

void	three_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int	temp;

	temp = find_max_intri_a(lista, listb);
	if (temp == 0)
	{
		pb(lista, listb, 1);
		arr[0] -= 1;
	}
	else if (temp == 1)
	{
		rrb(listb, 1);
		arr[1] -= 1;
	}
	else if (temp == 2)
	{
		rra(lista, 1);
		pb(lista, listb, 1);
		arr[2] -= 1;
	}
}

void	two_aa(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->tail->data < listb->tail->data)
	{
		rrb(listb, 1);
		arr[1] -= 1;
	}
	else
	{
		rra(lista, 1);
		pb(lista, listb, 1);
		arr[2] -= 1;
	}
}

void	two_ab(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->head->data > lista->tail->data)
	{
		pb(lista, listb, 1);
		arr[0] -= 1;
	}
	else
	{
		rra(lista, 1);
		pb(lista, listb, 1);
		arr[2] -= 1;
	}
}

void	two_ac(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (listb->tail->data > lista->head->data)
	{
		rrb(listb, 1);
		arr[1] -= 1;
	}
	else
	{
		pb(lista, listb, 1);
		arr[0] -= 1;
	}
}
