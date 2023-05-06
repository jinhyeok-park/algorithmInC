/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:56:18 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/10 10:10:43 by jinhyepa         ###   ########.fr       */
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
	{	
		*range = NULL;
		return (0);
	}
	*range = (int *)(malloc(sizeof(int) * len));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (len);
}
