/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:42:24 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/10 16:07:41 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_head(t_list_ps *list)
{
	t_node *temp;

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
			list->size--;
			free(temp);
		}
	}
}

void	pop_tail(t_list_ps *list)
{
	t_node *temp;

	if (list)
	{
		if (list->tail)
		{
			temp = list->tail;
			list->tail = temp->prev;
			list->tail->next = list->head;
			list->head->prev = list->tail;
			list->size--;
			free(temp);
		}
	}
}

int	push_head(t_list_ps *list, int data)
{
	t_node	*temp;

	if (list)
	{
		temp = create_node(data);
		if (!temp)
			return (0);
		if(list->head)
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
	return  (0);
}

int	push_tail(t_list_ps *list, int data)
{
	t_node *temp;

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
	t_node *ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		return (0);
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list_ps *temp;

// 	temp = (t_list_ps *)malloc(sizeof(t_list_ps));
// 	temp->head = NULL;
// 	temp->tail = NULL;
// 	temp->size = 0;
// 	push_head(temp, 1);
// 	push_tail(temp, 2);
// 	push_tail(temp, 3);
// 	sa(temp);
// 	list_printer(temp);
// }

//  void	list_printer(t_list_ps *list)
//  {
// 	int	temp;

// 	temp = list->size;
// 	while (temp--)
// 	{
// 		printf("%d\n", list->head->data);
// 		list->head = list->head->next;
// 	}
//  }

void	free_list(t_list_ps *list)
{
	t_node *throw;

	while (list->size--)
	{
		throw = list->head;
		list->head = list->head->next;
		free(throw);
	}
}