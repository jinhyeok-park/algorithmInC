/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:14:40 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:15:17 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_all_ad(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
		three_ad(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] > 0 && arr[2] == 0)
		two_acd(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] == 0 && arr[2] > 0)
		two_abd(lista, listb, arr);
	else if (arr[0] == 0 && arr[1] > 0 && arr[2] > 0)
		two_aad(lista, listb, arr);
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

void	three_ad(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int	temp;

	temp = find_min_tri_d(lista, listb);
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

void	two_aad(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->tail->data > listb->tail->data)
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

void	two_abd(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->head->data < lista->tail->data)
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

void	two_acd(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (listb->tail->data < lista->head->data)
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
