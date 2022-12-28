/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:10:40 by yim               #+#    #+#             */
/*   Updated: 2022/09/02 22:41:06 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_positive(char c, int positive)
{
	if (c == '-')
		positive *= -1;
	return (positive);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	positive;

	positive = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		positive = ft_positive(str[i], positive);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= positive;
	return (num);
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = "   ---+--+1234ab567";
	printf("%d", ft_atoi(str));
}
*/
