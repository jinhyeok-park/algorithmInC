/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:25:12 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/13 11:08:12 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_left(long long memory)
{
	int		i;
	char	mem_arr[16];

	i = 0;
	while (i < 16)
		mem_arr[i++] = 0;
	i = 0;
	while (i < 16)
	{
		mem_arr[15 - i] = "0123456789abcdef"[memory % 16];
		memory /= 16;
		i++;
	}
	write(1, mem_arr, 16);
}

void	ft_mid(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_right(unsigned char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] <= 31 || 127 <= str[i])
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	ft_print(long long memory, unsigned char *str, unsigned int len)
{
	ft_left(memory);
	write(1, ": ", 2);
	ft_mid(str, len);
	ft_right(str, len);
	write(1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	long long		memory;
	unsigned char	*str;
	unsigned int	i;
	unsigned int	col;
	unsigned int	remainder;

	if (!size)
		return ;
	memory = (long long)addr;
	str = (unsigned char *)addr;
	col = ((size / 16) * 16);
	remainder = size % 16;
	i = 0;
	while (i < col)
	{
		ft_print((memory + i), &str[i], 16);
		i += 16;
	}
	if (remainder)
	{
		ft_print((memory + i), &str[i], remainder);
	}
}
