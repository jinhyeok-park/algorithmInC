/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:50:55 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:40 by jinhyeok         ###   ########.fr       */
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
	char		*temp;

	ret = 0;
	sign = 1;
	temp = str;
	if (*temp == '-')
	{
		temp++;
		sign = -1;
	}
	while (*temp)
	{
		ret = ret * 10 + (*temp) - '0';
		temp++;
	}
	return (ret * sign);
}
