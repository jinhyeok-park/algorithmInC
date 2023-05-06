/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:07:00 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/11 14:53:01 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_printf(char digit1, char digit2, char digit3)
{
	char	temp[3];

	temp[0] = digit1;
	temp[1] = digit2;
	temp[2] = digit3;
	write (1, &temp, 3);
	if (!(digit1 == '7' && digit2 == '8' && digit3 == '9'))
		write (1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	digit1;
	char	digit2;
	char	digit3;

	digit1 = '0';
	while (digit1 <= '9')
	{
		digit2 = '0';
		while (digit2 <= '9')
		{
			digit3 = '0';
			while (digit3 <= '9')
			{
				if (digit1 < digit2 && digit2 < digit3)
				{
					ft_printf(digit1, digit2, digit3);
				}
				digit3++;
			}
			digit2++;
		}
		digit1++;
	}
}
