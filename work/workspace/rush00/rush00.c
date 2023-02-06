/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujinlee <yujinlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:50:57 by yujinlee          #+#    #+#             */
/*   Updated: 2023/01/14 11:18:39 by yujinlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	output_char(int x, int y, int i, int j)
{

	if (i == 1 || i == y)
	{
		if (j == 1 || j == x)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (j == 1 || j == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}


void	print(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			output_char(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 1;
	}
}

void rush(int x, int y)
{
	if (!(x <= 0 || y <= 0))
	{
		print(x, y); 
	}
	else
	{
		write(1, "Error", 5);
	}
}
