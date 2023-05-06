/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:06:01 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/28 13:26:25 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_convert2(char *dict, char *num)
{
	char	*n;
	int		n_len;
	int		sep_num;

	n = ft_no_comma(num, 0);
	n_len = ft_strlen(n);
	sep_num = (n_len - 1) / 3;
	while (sep_num + 1)
	{
		ft_print_nnnv1(dict, n, sep_num);
		ft_print_sep(dict/*, n*/, sep_num);
		sep_num--;
	}
}

void	ft_convert(char *str)
{
	char	*dict;
	int		d_len;
	int		fd;

	if (ft_not_good(str))
	{
		write(1, "Error", 5);
		return ;
	}
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error", 10);
		close(fd);
		return ;
	}
	d_len = ft_file_len(open("numbers.dict", O_RDONLY));
	dict = ft_file_dup(open("numbers.dict", O_RDONLY), d_len);
	ft_convert2(dict, str);
}

void	ft_converts(char *dic, char *str)
{
	char	*dict;
	int		d_len;
	int		fd;

	if (ft_not_good(str))
	{
		write(1, "Error", 5);
		return ;
	}
	fd = open(dic, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error", 10);
		close(fd);
		return ;
	}
	d_len = ft_file_len(open(dic, O_RDONLY));
	dict = ft_file_dup(open(dic, O_RDONLY), d_len);
	ft_convert2(dict, str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_convert(av[1]);
		write(1, "\n", 1);
	}
	else if (ac == 3)
	{
		ft_converts(av[1], av[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "Error\n", 6);
}
