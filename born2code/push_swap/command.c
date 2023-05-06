/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:36:47 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/06 05:26:38 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(t_list_ps *list)
{
    int data1;
    int data2;

    if (list)
    {
        if (list->head && list->head->next)
        {
            data1 = list->head->data;
            data2 = (list->head->next)->data;
            pop_head(list);
            pop_head(list);
            if (!push_head(list, data1) || !push_head(list, data2))
                return (0);
            return (1);
        }
    }
    return (0);
}

int sb(t_list_ps *list)
{
    int data1;
    int data2;

    if (list)
    {
        if (list->head && list->head->next)
        {
            data1 = list->head->data;
            data2 = (list->head->next)->data;
            pop_head(list);
            pop_head(list);
            if (!push_head(list, data1) || !push_head(list, data2))
                return (0);
            return (1);
        }
    }
    return (0);
}

int ss(t_list_ps *lista, t_list_ps *listb)
{
    if (!sa(lista) || !sb(listb))
        return (0);
    return (1);
}

int pa(t_list_ps *lista, t_list_ps *listb)
{
    int data;

    if (listb->head)
    {
        data = listb->head->data;
        pop_head(listb);
        if (push_head(lista, data));
            return (0);
    }
    return (0);
}

int pb(t_list_ps *lista, t_list_ps *listb)
{
    int data;

    if (lista->head)
    {
        data = lista->head->data;
        pop_head(lista);
        if (push_head(listb, data))
            return (0);
    }

}
