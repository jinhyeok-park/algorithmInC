/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:23:33 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/09 13:34:14 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    sa(t_list_ps *list)
{
    t_node *temp;

    if (!list->head || !list->head->next)
        return (0);
    temp = list->head->next;
    list->head->next = temp->next;
    list->head->prev = temp;
    temp->next = list->head;
    temp->prev = list->tail;
    return (1);
}

int    sb(t_list_ps *list)
{
    t_node *temp;

    if (!list->head || !list->head->next)
        return (0);
    temp = list->head->next;
    list->head->next = temp->next;
    list->head->prev = temp;
    temp->next = list->head;
    temp->prev = list->tail;
    return (1);
}

int ss(t_list_ps *lista, t_list_ps* listb)
{
    if (!sa(lista) || sb(listb))
        return (0);
    return (1);
}

int pa(t_list_ps *lista, t_list_ps* listb)
{
    t_node *temp;

    temp = listb->head;
    
}
int pa(t_list_ps *lista, t_list_ps* listb)
int pa(t_list_ps *lista, t_list_ps* listb)
int pa(t_list_ps *lista, t_list_ps* listb)
int pa(t_list_ps *lista, t_list_ps* listb)
int pa(t_list_ps *lista, t_list_ps* listb)
int pa(t_list_ps *lista, t_list_ps* listb)
int pa(t_list_ps *lista, t_list_ps* listb)