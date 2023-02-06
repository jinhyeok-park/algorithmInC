/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:18:11 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/17 18:13:43 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_make_combination(int arrIndex, char startW, char *arr, int n)
{
	if (arrIndex == n)
	{
		write(1, arr, n);
		if (arr[0] - '0' < 10 - n)
			write(1, ", ", 2);
		return ;
	}
	if (startW > '9')
	{
		return ;
	}
	arr[arrIndex] = startW;
	ft_make_combination(arrIndex + 1, startW + 1, arr, n);
	ft_make_combination(arrIndex, startW + 1, arr, n);
}

void	ft_print_combn(int n)
{
	char	arr[10];

	ft_make_combination(0, '0', arr, n);
}	
int main(void)
{
	ft_print_combn(9);
}
