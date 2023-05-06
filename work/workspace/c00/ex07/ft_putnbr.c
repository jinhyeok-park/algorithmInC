/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:51:28 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/10 21:12:27 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_recur_number(int num)
{
	char	output;

	if (num == 0)
	{
		return ;
	}
	else
	{
		ft_recur_number(num / 10);
	}
	output = num % 10 + '0';
	write(1, &output, 1);
}

void	ft_putnbr(int nb)
{
	int	sign;

	sign = 1;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		sign = -1;
		write(1, "-", 1);
		nb = nb * sign;
	}
	ft_recur_number(nb);
}
