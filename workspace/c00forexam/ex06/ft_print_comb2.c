/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:17:28 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/08/28 13:44:51 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printcm(int n, int k)
{
	if (!((n == 98) && (k == 99)))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	arr1[2];
	char	arr2[2];

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			arr1[0] = a / 10 + '0';
			arr1[1] = a % 10 + '0';
			write(1, arr1, 2);
			write(1, " ", 1);
			arr2[0] = b / 10 + '0';
			arr2[1] = b % 10 + '0';
			write(1, arr2, 2);
			printcm(a, b);
			b++;
		}
		a++;
	}
}
