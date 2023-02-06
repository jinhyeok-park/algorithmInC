/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:42:11 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 06:53:36 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_start(int r)
{
	char	a;
	char	buf[1024];
	int		i;

	i = 0;
	while (r)
	{
		r = read(0, &a, 1);
		if (a == '\n')
		{
			buf[i] = '\0';
			i = 0;
			ft_convert(buf);
		}
		buf[i] = a;
		i++;
	}
}

void	ft_print_nnnv3(char *dict, char *n3, int i, int sep_num)
{
	char	*d;

	if (i == 3)
	{
		d = malloc(2);
		d[0] = n3[0];
		d[1] = '\0';
		ft_print_n(dict, d, 1);
		free(d);
		ft_print_100(dict, n3);
		ft_print_nm(dict, &n3[1], sep_num);
	}
	else if (i == 2)
		ft_print_nm(dict, &n3[1], sep_num);
	else if (i == 1)
		ft_print_n(dict, &n3[2], sep_num);
}

void	ft_print_nnnv2(char *dict, char *n3, int i, int sep_num)
{
	if (n3[0] == '0' && n3[1] == '0' && n3[2] == '0')
		return ;
	else if ((n3[0] == '0' || n3[0] == '\0') && (n3[1] == '0' || n3[1] == '\0'))
		i = 1;
	else if ((n3[0] == '0' || n3[0] == '\0') && n3[1] != '0' && n3[2] != '0')
		i = 2;
	ft_print_nnnv3(dict, n3, i, sep_num);
}

void	ft_print_nnnv1(char *dict, char *n, int sep_num)
{
	int		num_of_zero;
	int		i;
	char	*n3;

	if (sep_num == 0 && *n == '0')
	{
		ft_print_n(dict, "0", sep_num);
		return ;
	}
	num_of_zero = 3 * sep_num;
	while (*n && *n >= '0' && *n <= '9')
		n++;
	n -= num_of_zero;
	n3 = malloc(4);
	i = 4;
	while (i)
		n3[i-- - 1] = '\0';
	while (*(n - 1) >= '0' && *(n - 1) <= '9' && 3 - i)
	{
		n--;
		n3[2 - i] = *n;
		i++;
	}
	ft_print_nnnv2(dict, n3, i, sep_num);
	free(n3);
}

int	ft_too_long(int n_len, char *dict)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	i = 0;
	while (dict[i])
	{
		if (dict[i] == '\n')
		{
			if (max < count)
				max = count;
			count = 0;
		}
		if (dict[i] >= '0' && dict[i] <= '9')
			count++;
		i++;
	}
	if (n_len > max + 2)
		return (1);
	return (0);
}
