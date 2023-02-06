/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:08:04 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/12 12:09:57 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (tab[i] > tab[k])
			{
				temp = tab[i];
				tab[i] = tab[k];
				tab[k] = temp;
			}
			k++;
		}
		i++;
	}
}
