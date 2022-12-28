/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:16:46 by seycho            #+#    #+#             */
/*   Updated: 2022/09/03 23:28:48 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_colup(int res[][4], int *colup)
{
	int	i;
	int	j;
	int	max;
	int	count;

	i = 0;
	while (i < 4)
	{
		count = 1;
		j = 0;
		max = res[j][i];
		while (j < 4)
		{
			if (res[j][i] > max)
			{
				max = res[j][i];
				count++;
			}
			j++;
		}
		if (count != colup[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_coldown(int res[][4], int *coldown)
{
	int	i;
	int	j;
	int	max;
	int	count;

	i = 0;
	while (i < 4)
	{
		count = 1;
		j = 3;
		max = res[j][i];
		while (j >= 0)
		{
			if (res[j][i] > max)
			{
				max = res[j][i];
				count++;
			}
			j--;
		}
		if (count != coldown[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_rowleft(int res[][4], int *rowleft)
{
	int	i;
	int	j;
	int	max;
	int	count;

	i = 0;
	while (i < 4)
	{
		count = 1;
		j = 0;
		max = res[i][j];
		while (j < 4)
		{
			if (res[i][j] > max)
			{
				max = res[i][j];
				count++;
			}
			j++;
		}
		if (count != rowleft[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_rowright(int res[][4], int *rowright)
{
	int	i;
	int	j;
	int	max;
	int	count;

	i = 0;
	while (i < 4)
	{
		count = 1;
		j = 3;
		max = res[i][j];
		while (j >= 0)
		{
			if (res[i][j] > max)
			{
				max = res[i][j];
				count++;
			}
			j--;
		}
		if (count != rowright[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_num(int res[][4], int num[][4])
{
	if (!check_colup(res, num[0]))
		return (0);
	if (!check_coldown(res, num[1]))
		return (0);
	if (!(check_rowleft(res, num[2])))
		return (0);
	if (!(check_rowright(res, num[3])))
		return (0);
	return (1);
}
/*
int main()
{
	int num[4][4] = {4,3,1,2,1,2,2,2,4,3,2,1,1,2,2,2};
	int res[4][4] = {1,2,3,4,2,3,4,1,3,4,1,2,4,1,2,3};
	printf("%d\n", ft_check_num(res, num));

	return 0;
}*/
