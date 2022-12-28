/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:18:40 by seminkim          #+#    #+#             */
/*   Updated: 2022/09/03 22:13:55 by seminkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(int res[4][4])
{
	int		i;
	int		j;
	char	c;
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4){
			c = res[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
}

int	ft_check(int x, int y, int res[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < x)
	{
		if (res[y][j] == res[y][x])
			return (0);
		j ++ ;
	}
	while (i < y)
	{
		if (res[i][x] == res[y][x])
			return (0);
		i ++;
	}
	return (1);
}

int	ft_check_num(int res[4][4], int num[4][4])
{
	int i;
	int j;
	int k;
	int number;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			k = 0;
			if (i == 0)
			{
				number = 1;
				while (k < 4)
				{
					if (res[k][j] == 4)
						break ;
					else
					{
						if (res[k][j] < res[k+1][j])
							number ++;
					}
					k ++; 
				}
				if (number != num[i][j])
					return (0);
			}
			j ++;
		}
		i ++;
	}
	return (1);
}

void rush(int x, int y, int res[4][4], int num[4][4])
{
	int otf;
	int i;
	int j;

	otf = 1;
	if(y < 4 && x < 4)
	{
		while (otf < 5)
		{
			res[y][x] = otf ++;
			if (ft_check(x, y, res))
			{
				if (x == 3 && y == 3)
				{
					if(ft_check_num(res, num))
						ft_putchar(res);
				}
				else if (x == 3)
					rush(0, y + 1, res, num);
				else
					rush(x + 1, y, res, num);
			}
		}
	}
}

int main()
{
	int num[4][4] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2};
	int	res[4][4];
	int x;
	int y;

	x = 0;
	y = 0;
	rush(x, y, res, num);
}
