/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:15 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/03 16:38:56 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(void)
{
	t_list  *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_list	*push_head(t_list *list, int data)
{
	t_node	*temp;

	if (!list)
		return (0);
	if (!list->head)
	{
		list->head = malloc(sizeof(t_node));
		if (!list->head)
		{
			free(list);
			return (0);
		}
		list->head->data = data;
		list->head->next = NULL;
		list->head->prev = NULL;
	}
	else
	{




	}
	return (list);
}

t_list	*create_node(t_list *list)
{
	

}

void	free_list(t_list *list)
{
	t_node	*temp;

	while (list->head)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	free(list);
}