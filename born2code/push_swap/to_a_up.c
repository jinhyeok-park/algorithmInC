/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:42 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 21:53:26 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_all(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
		three(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] > 0 && arr[2] == 0)
		two_c(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] == 0 && arr[2] > 0)
		two_b(lista, listb, arr);
	else if (arr[0] == 0 && arr[1] > 0 && arr[2] > 0)
		two_a(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] == 0 && arr[2] == 0)
	{
		pa(lista, listb, 1);
		arr[0] -= 1;
	}
	else if (arr[0] == 0 && arr[1] > 0 && arr[2] == 0)
	{
		rra(lista, 1);
		arr[1] -= 1;
	}
	else if (arr[0] == 0 && arr[1] == 0 && arr[2] > 0)
		one(lista, listb, arr);
}

void	two_a(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->tail->data > listb->tail->data)
	{
		rra(lista, 1);
		arr[1] -= 1;
	}
	else
	{
		rrb(listb, 1);
		pa(lista, listb, 1);
		arr[2] -= 1;
	}
}

void	two_b(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (listb->head->data > listb->tail->data)
	{
		pa(lista, listb, 1);
		arr[0] -= 1;
	}
	else
	{
		rrb(listb, 1);
		pa(lista, listb, 1);
		arr[2] -= 1;
	}
}

void	two_c(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->tail->data > listb->head->data)
	{
		rra(lista, 1);
		arr[1] -= 1;
	}
	else
	{
		pa(lista, listb, 1);
		arr[0] -= 1;
	}
}

void	three(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int	temp;

	temp = find_max_intri(lista, listb);
	if (temp == 0)
	{
		pa(lista, listb, 1);
		arr[0] -= 1;
	}
	else if (temp == 1)
	{
		rra(lista, 1);
		arr[1] -= 1;
	}
	else if (temp == 2)
	{
		rrb(listb, 1);
		pa(lista, listb, 1);
		arr[2] -= 1;
	}
}
