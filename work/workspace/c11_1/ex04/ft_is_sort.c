/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:20:28 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/30 10:57:32 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag2;
	int	flag1;

	i = 0;
	flag1 = 0;
	flag2 = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			flag1 = 1;
		if (f(tab[i], tab[i + 1]) < 0)
			flag2 = 1;
		i++;
	}
	if ((flag1 + flag2) == 2)
		return (0);
	return (1);
}
