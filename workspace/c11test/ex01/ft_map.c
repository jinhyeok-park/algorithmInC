/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:10:32 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 12:09:22 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		*result;

	result = (int *)malloc(sizeof(int) * length);
	while (i < legnth)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
