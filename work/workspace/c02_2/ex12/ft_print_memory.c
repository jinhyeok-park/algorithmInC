/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:04:49 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/21 12:11:48 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_hex(long long mem)
{
	char	memar[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		memar[15 - i] = "0123456789abcdef"[mem % 16];
		mem /= 16;
		i++;
	}
	write(1, memar, 16);
}

void	ft_print_comb_hex(unsigned char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	if (size < 16)
	{
		while (i < 16 - size)
		{
			write(1, "  ", 2);
			if (i % 2 == 1)
				write(1, " ", 1);
			i++;
		}
	}
}

void	ft_print_word(unsigned char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == 0)
		{
			write(1, ".", 1);
		}
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	print_all(unsigned char *str, long long mem, int size)
{
	ft_print_hex(mem);
	write(1, ": ", 2);
	ft_print_comb_hex(str, size);
	ft_print_word(str, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	rest;
	long long		mem;
	unsigned char	*str;

	i = 0;
	if (size == 0)
		return (0);
	rest = size % 16;
	size = size - rest;
	mem = (long long)addr;
	str = (unsigned char *)addr;
	while (i < size)
	{
		print_all(str + i, mem + i, 16);
		write(1, "\n", 1);
		i += 16;
	}
	if (rest)
	{
		print_all(str + i, mem + i, rest);
		write(1, "\n", 1);
	}
	return (addr);
}

int main(void)
{
	char str[92] =
{0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20,
 0x6c, 0x65, 0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e,
 0x63, 0x68, 0x65, 0x73, 0x09, 0x0a, 0x09, 0x63,
 0x20, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f,
 0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63,
 0x65, 0x20, 0x71, 0x75, 0x20, 0x6f, 0x6e, 0x20,
 0x70, 0x65, 0x75, 0x74, 0x20, 0x66, 0x61, 0x69,
 0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09,
 0x0a, 0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f,
 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x0a, 0x0a,
 0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f,
 0x6c, 0x0a, 0x20, 0x00};
ft_print_memory(str,92);

}
