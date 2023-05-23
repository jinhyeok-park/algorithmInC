/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:50:55 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/22 22:18:26 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(1, "Error\n", 6);
}

long long	ft_atoll(char *str)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		ret = ret * 10 + (*str) - '0';
		str++;
	}
	return (ret * sign);
}
