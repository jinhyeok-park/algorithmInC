/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:56:18 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/07 17:55:13 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		len;
	int		i;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	*range = (int *)(malloc(sizeof(int) * len));
	if (!*range)
		return (0);
	while (min < max)
	{
		*range[i] = min;
		min++;
		i++;
	}
	return (len);
}
