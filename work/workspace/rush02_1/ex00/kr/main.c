/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:06:01 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 06:53:39 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_dot(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i] == '.')
			return (1);
		i++;
	}
	i = 0;
	while ((n[i] < '0' || n[i] > '9') && n[i])
		i++;
	if (n[i] == '\0')
		return (1);
	return (0);
}

void	ft_convert2(char *dict, char *n, int s)
{
	int		n_len;
	int		sep_num;
	char	*p;

	n_len = ft_strlen(n) * (n != 0) + (!n);
	sep_num = (n_len - 1) / 3;
	if (ft_too_long(n_len, dict))
	{
		write(2, "Dict Error", 10);
		return ;
	}
	if (s == -1 && *n != '0')
		write(1, "negative ", 9);
	p = n;
	while (*p)
		p++;
	while (sep_num + 1)
	{
		ft_print_nnnv1(dict, n, sep_num);
		ft_print_sep(dict, p, sep_num);
		sep_num--;
	}
}

void	ft_convert(char *str)
{
	char	*dict;
	int		d_len;
	int		fd;
	int		shift;

	shift = 0;
	if ((ft_not_good(str, &shift, 0, 1) == 0) || ft_dot(str))
	{
		write(2, "Error", 5);
		return ;
	}
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error", 10);
		close(fd);
		return ;
	}
	d_len = ft_file_len(open("numbers.dict", O_RDONLY));
	dict = ft_file_dup(open("numbers.dict", O_RDONLY), d_len);
	ft_convert2(dict, str + shift, ft_not_good(str, &shift, 0, 1));
	free(dict);
	write(1, "\n", 1);
}

void	ft_converts(char *dic, char *str)
{
	char	*dict;
	int		d_len;
	int		fd;
	int		shift;

	shift = 0;
	if (ft_not_good(str, &shift, 0, 1) == 0 || ft_dot(str))
	{
		write(2, "Error", 5);
		return ;
	}
	fd = open(dic, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error", 10);
		close(fd);
		return ;
	}
	d_len = ft_file_len(open(dic, O_RDONLY));
	dict = ft_file_dup(open(dic, O_RDONLY), d_len);
	ft_convert2(dict, str + shift, ft_not_good(str, &shift, 0, 1));
	free(dict);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_start(1);
	else if (ac == 2)
		ft_convert(av[1]);
	else if (ac == 3)
		ft_converts(av[1], av[2]);
	else
		write(2, "Error\n", 6);
}
