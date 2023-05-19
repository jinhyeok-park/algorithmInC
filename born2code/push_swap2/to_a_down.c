/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:19:36 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/19 21:20:18 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_all_d(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (arr[0] ==3 && arr[1]== 5 && arr[2] == 3)
	{
		printf("in");
	}
	int	aa = arr[0];
	int	bb = arr[1];
	int	cc = arr[2];
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
		three_d(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] > 0 && arr[2] == 0)
		two_dc(lista, listb, arr);
	else if (arr[0] > 0 && arr[1] == 0 && arr[2] > 0)
		two_db(lista, listb, arr);
	else if (arr[0] == 0 && arr[1] > 0 && arr[2] > 0)
		two_da(lista, listb, arr);
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

void	three_d(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	int temp;

	temp = find_min_tri(lista, listb);
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

void	two_db(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (listb->head->data < listb->tail->data)
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

void	two_dc(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (lista->tail->data < listb->head->data)
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

void	two_da(t_list_ps *lista, t_list_ps *listb, int *arr)
{
	if (!lista->tail || lista->size == 0 || listb->size == 0 || !listb || !lista || !listb->tail)
	{
	}
	printf("%d", lista->tail->data);
	print_a_b(lista, listb);
	for (int i = 0 ; i < 3 ; i ++)
	{
		printf("%d", arr[i]);
	}
	exit(1);
	if (lista->tail->data < listb->tail->data)
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