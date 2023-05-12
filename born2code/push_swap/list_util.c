/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:15 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/09 13:23:14 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*create_list(void)
{
	t_list_ps  *list;

	list = (t_list_ps *)malloc(sizeof(t_list_ps));
	if (!list)
		return (0);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

// t_list_ps	*push_head(t_list_ps *list, int data)
// {
// 	t_node	*temp;

// 	if (!list->head)
// 	{
// 		list->head = create_node(data);
// 		if (!list->head)
// 		{
// 			free(list);
// 			return (0);
// 		}
// 		list->tail = list->head;
// 	}
// 	else
// 	{
// 		temp = list->head;
// 		list->head = create_node(data);
// 		if (!list->head)
// 		{
// 			free_list(list);
// 			return (0);
// 		}
// 		list->head->next = temp;
// 		temp->prev = list->head;
// 	}
// 	return (list);
// }

// t_node	*create_node(int data)
// {
// 	t_node	*ret;

// 	ret = (t_node *)malloc(sizeof(t_node));
// 	if (!ret)
// 		return (0);
// 	ret->data = data;
// 	ret->next = NULL;
// 	ret->prev = NULL;
// 	return (ret);
// }

// void	pop_tail(t_list_ps *list)
// {
// 	t_node *temp;
	
// 	temp = list->tail;
// 	list->tail = (list->tail)->prev;
// 	list->tail->next = NULL;
// 	free(temp);
// }

// void	pop_head(t_list_ps *list)
// {
// 	t_node *temp;

// 	temp = list->head;
// 	list->head = (list->head)->next;
// 	list->head->
// }


// void	free_list(t_list_ps *list)
// {
// 	t_node	*temp;

// 	while (list->head)
// 	{
// 		temp = list->head;
// 		list->head = list->head->next;
// 		free(temp);
// 	}
// 	free(list);
// }