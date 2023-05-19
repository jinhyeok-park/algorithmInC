/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/03 14:28:48 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_self(long long *new_av, long long cur, int idx)
{
    int i;

    i = 0;
    while (i < idx)
    {
        if (new_av[i] == cur)
            return (0);
        i++;
    }
    return (1);
}