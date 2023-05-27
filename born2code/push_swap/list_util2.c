/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:42:24 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/27 19:19:18 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_head(t_list_ps *list)
{
	t_node	*temp;

	if (list)
	{
		if (list->size == 1)
		{
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		if (list->head)
		{
			temp = list->head;
			list->head = temp->next;
			list->head->prev = list->tail;
			list->tail->next = list->head;
			free(temp);
		}
		list->size--;
	}
}

void	pop_tail(t_list_ps *list)
{
	t_node	*temp;

	if (list)
	{
		if (list->size == 1)
		{
			free(list->tail);
			list->head = NULL;
			list->tail = NULL;
		}
		if (list->tail)
		{
			temp = list->tail;
			list->tail = temp->prev;
			list->tail->next = list->head;
			list->head->prev = list->tail;
			free(temp);
		}
		list->size--;
	}
}

int	push_head(t_list_ps *list, int data)
{
	t_node	*temp;

	if (list)
	{
		temp = create_node(data);
		if (list->head)
		{
			(list->head)->prev = temp;
			temp->next = list->head;
			temp->prev = list->tail;
			(list->tail)->next = temp;
			list->head = temp;
		}
		else
		{
			list->head = temp;
			list->tail = temp;
		}
		list->size++;
		return (1);
	}
	return (0);
}

int	push_tail(t_list_ps *list, int data)
{
	t_node	*temp;

	if (list)
	{
		if (push_head(list, data))
		{
			if (list->size == 1)
				return (1);
			temp = list->head;
			list->head = list->head->next;
			list->tail = temp;
			return (1);
		}
	}
	return (0);
}

t_node	*create_node(int data)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		exit (1);
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
