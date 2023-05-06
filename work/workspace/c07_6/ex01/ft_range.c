/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:13:41 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/23 14:17:50 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;
	int	len;

	i = 0;
	len = ft_abs(min - max);
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (0);
	if (min >= max)
		return (0);
	while (min < max)
	{
		result[i] = min++;
		i++;
	}
	return (result);
}
