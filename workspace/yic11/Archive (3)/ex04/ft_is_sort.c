/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <yim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:12:11 by yim               #+#    #+#             */
/*   Updated: 2022/09/12 11:51:24 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	flag1;
	int	flag2;

	i = 0;
	flag1 = 0;
	flag2 = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if ((*f)(tab[i], tab[j]) > 0)
				flag1 = 1;
			if ((*f)(tab[i], tab[j]) < 0)
				flag2 = 1;
			j++;
		}
		i++;
	}
	if (flag1 + flag2 != 2)
		return (1);
	return (0);
}
