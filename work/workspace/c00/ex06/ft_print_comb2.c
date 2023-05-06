/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:22:38 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/11 14:55:19 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_num(int num1, int num2)
{
	char	digit1[2];
	char	digit2[2];

	digit1[0] = num1 / 10 + '0';
	digit1[1] = num1 % 10 + '0';
	digit2[0] = num2 / 10 + '0';
	digit2[1] = num2 % 10 + '0';
	write (1, digit1, 2);
	write (1, " ", 1);
	write (1, digit2, 2);
	if (!(num2 == 99 && num1 == 98))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	first_num;
	int	sec_num;

	first_num = 0;
	while (first_num < 99)
	{
		sec_num = first_num + 1;
		while (sec_num < 100)
		{
			ft_print_num(first_num, sec_num);
			sec_num++;
		}
		first_num++;
	}
}
