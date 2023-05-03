/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:38:54 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/03 16:37:31 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *make_list(int ac, char **av, int len)
{
    long long   *new_av;
    t_list      *list;

    new_av = make_new_av(ac, av);
    if (!new_av)
        return (0);
    list = create_list();
    if (!list)
        return (0);
    while (len)
    {
        len--;
        list->head = push_head(list, new_av[len]);
        if (!list->head)
            return (0);
    }
    return (list);
}