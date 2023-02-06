/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:58:59 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/11 16:08:50 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	start;

	start = 'a';
	start--;
	while (start ++ < 'z')
		write (1, &start, 1);
}
int main(void)
{
	ft_print_alphabet();
}
