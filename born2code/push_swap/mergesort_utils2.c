/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:29 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:28:24 by jinhyeok         ###   ########.fr       */
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
	sup_5(lista, listb, i, size);
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

// void	print_a_b(t_list_ps *lista, t_list_ps *listb)
// {
// 	t_node *temp;

// 	temp = lista->head;
// 	printf("\nlista print\n");
// 	if (temp == NULL)
// 		printf("NULL");
// 	for (int i = 0 ; i < lista->size; i++)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	printf("\nlistb print\n");
// 	temp = listb->head;
// 	if (temp == NULL)
// 		printf("NULL");
// 	for (int i = 0 ; i < listb->size; i++)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// }
