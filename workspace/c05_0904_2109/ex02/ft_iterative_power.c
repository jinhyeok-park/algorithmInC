/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:30:14 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/04 21:41:01 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if (nb < 0)
		return (0);
	while(i < power)
	{
		result *= nb;
		i ++;
	}
	return (result);
}
#include<stdio.h>
int main(void)
{
	printf("%d", ft_iterative_power(0,0));
}
