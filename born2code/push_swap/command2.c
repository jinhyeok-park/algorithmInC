/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:36:47 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 21:39:26 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list_ps *list, int flag)
{
	int	data1;
	int	data2;

	if (list)
	{
		if (list->head && list->head->next)
		{
			data1 = list->head->data;
			data2 = (list->head->next)->data;
			pop_head(list);
			pop_head(list);
			push_head(list, data1);
			push_head(list, data2);
			if (flag)
				write(1, "sa\n", 3);
			return (1);
		}
	}
	return (0);
}

int	sb(t_list_ps *list, int flag)
{
	int	data1;
	int	data2;

	if (list)
	{
		if (list->head && list->head->next)
		{
			data1 = list->head->data;
			data2 = (list->head->next)->data;
			pop_head(list);
			pop_head(list);
			push_head(list, data1);
			push_head(list, data2);
			if (flag)
				write(1, "sb\n", 3);
			return (1);
		}
	}
	return (0);
}

int	pa(t_list_ps *lista, t_list_ps *listb, int flag)
{
	int	data;

	if (listb->size == 0)
		return (0);
	if (listb->head)
	{
		data = listb->head->data;
		pop_head(listb);
		push_head(lista, data);
		if (flag)
			write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	pb(t_list_ps *lista, t_list_ps *listb, int flag)
{
	int	data;

	if (lista->head)
	{
		data = lista->head->data;
		pop_head(lista);
		push_head(listb, data);
		if (flag)
			write(1, "pb\n", 3);
	}
	return (1);
}
