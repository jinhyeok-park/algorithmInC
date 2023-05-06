/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:16:22 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/08/27 22:22:26 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	variable(char a, char b, char c)
{
	if (a < b && b < c)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		if (!(a == '7' && b == '8' && c == '9'))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	num1;
	char	num3;
	char	num2;

	num1 = '0';
	while (num1 <= '9')
	{
		num2 = '0';
		while (num2 <= '9')
		{
			num3 = '0';
			while (num3 <= '9' )
			{
				variable(num1, num2, num3);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}
