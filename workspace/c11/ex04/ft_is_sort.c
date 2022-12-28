/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:58:33 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 12:07:22 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		check1;
	int		check2;

	i = 0;
	check1 = 0;
	check2 = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			check1 = 1;
		if (f(tab[i], tab[i + 1]) < 0)
			check2 = 1;
		i++;
	}
	if (check1 + check2 == 2)
		return (0);
	return (1);
}
