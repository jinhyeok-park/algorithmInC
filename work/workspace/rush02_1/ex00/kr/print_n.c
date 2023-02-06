/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:36:11 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 05:34:24 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_100(char *dict, char *n3)
{
	char	*p;

	p = ft_strstr(dict, "100");
	while (*p >= '0' && *p <= '9')
		p++;
	while (*p == ' ' || *p == ':')
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	if (n3[1] == '0' && n3[2] == '0')
		write(1, " ", 1);
	else
		write(1, " and ", 5);
}

void	ft_print_n(char *dict, char *n, int sep_num)
{
	char	*p;

	p = ft_strstr(dict, n);
	while (*p >= '0' && *p <= '9')
		p++;
	while (*p == ' ' || *p == ':')
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	if (sep_num)
		write(1, " ", 1);
}

void	ft_print_1n(char *dict, char *n, int sep_num)
{
	char	*p;
	char	*needle;

	needle = malloc(3);
	needle[0] = '1';
	needle[1] = *(n + 1);
	needle[2] = '\0';
	p = ft_strstr(dict, needle);
	free(needle);
	while (*p >= '0' && *p <= '9')
		p++;
	while (*p == ' ' || *p == ':')
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	if (sep_num)
		write(1, " ", 1);
}

void	ft_print_n0(char *dict, char *n, int sep_num)
{
	char	*p;
	char	*needle;

	needle = malloc(3);
	needle[0] = *n;
	needle[1] = '0';
	needle[2] = '\0';
	p = ft_strstr(dict, needle);
	free(needle);
	while (*p >= '0' && *p <= '9')
		p++;
	while (*p == ' ' || *p == ':')
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	if (sep_num || *(n + 1) != '0')
		write(1, " ", 1);
}

void	ft_print_nm(char *dict, char *n, int sep_num)
{
	if (n[0] == '0' && n[1] == '0')
		return ;
	if (*n == '1')
		ft_print_1n(dict, n, sep_num);
	else if (*n == 0)
		ft_print_n(dict, n + 1, sep_num);
	else
	{
		ft_print_n0(dict, n, sep_num);
		if (*(n + 1) != '0')
			ft_print_n(dict, n + 1, sep_num);
	}
}
