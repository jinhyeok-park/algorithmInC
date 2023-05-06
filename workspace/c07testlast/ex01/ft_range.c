/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:09:27 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/07 17:56:28 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int		*range;
	int		len;
	int		*result;

	if (min >= max)
		return (0);
	len = max - min;
	range = (int *)malloc(sizeof(int) * len);
	if (!range)
		return (0);
	result = range;
	while (min < max)
	{
		*range = min;
		min++;
		range++;
	}
	return (result);
}
