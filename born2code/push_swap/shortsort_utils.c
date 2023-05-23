/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:16:27 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/18 20:24:33 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_changer(t_list_ps *list)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = list->head->data;
	temp2 = list->head->next->data;
	temp3 = list->tail->data;
	if (temp1 < temp2 && temp2 < temp3)
		return (0);
	if (temp1 < temp2 && temp3 < temp2 && temp2 > temp1 && temp3 > temp1)
		return (132);
	else if (temp1 > temp2 && temp1 > temp3 && temp2 < temp3 && temp2 < temp1)
		return (312);
	else if (temp1 > temp2 && temp1 > temp3 && temp3 < temp2 && temp3 < temp1)
		return (321);
	else if (temp1 > temp2 && temp3 > temp2 && temp3 > temp1 && temp3 > temp2)
		return (213);
	else if (temp3 < temp2 && temp3 < temp2 && temp3 < temp1 && temp3 < temp2)
		return (231);
	return (0);
}

void	push_minval_to_(t_list_ps *lista, t_list_ps *listb)
{
	t_node	*temp;
	int		min;
	int		i;

	temp = lista->head;
	min = temp->data;
	i = -1;
	while (++i < lista->size)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	i = val_index(lista, min);
	if (i < lista->size / 2)
		ra_p(lista, listb, min);
	else
		rra_p(lista, listb, min);
}

void	rra_p(t_list_ps *lista, t_list_ps *listb, int data)
{
	while (1)
	{
		if (lista->head->data == data)
		{
			pb(lista, listb, 1);
			break ;
		}
		rra(lista, 1);
	}
}

void	ra_p(t_list_ps *lista, t_list_ps *listb, int data)
{
	while (1)
	{
		if (lista->head->data == data)
		{
			pb(lista, listb, 1);
			break ;
		}
		ra(lista, 1);
	}
}

int	val_index(t_list_ps *list, int data)
{
	int		i;
	t_node	*node;

	i = 0;
	node = list->head;
	while (i < list->size)
	{
		if (node->data == data)
			break ;
		i++;
		node = node->next;
	}
	return (i);
}
