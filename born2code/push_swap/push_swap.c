/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:21:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/03 14:09:00jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char ** av)
{
    t_list  *list;

    if (ac < 2 || (av_count(ac, av) < 2))
        return (0);
    if (!check_input(ac, av))
    {
        error_msg();
        return (0);
    }
    list = make_list(ac, av);
    if (!list)
        return (0);
    if (sort_merge(list))
        printf("ok");
    else
        printf("ko");
}