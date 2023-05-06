/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:36:11 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/28 16:35:10 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_100(char *dict)
{
	char	*p;

	p = ft_strstr(dict, "100");
	while (*p == ' ' || *p == ':' || (*p >= '0' && *p <= '9'))
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	write(1, " ", 1);
}

void	ft_print_n(char *dict, char *n)
{
	char	*p;

	p = ft_strstr(dict, n);
	while (*p == ' ' || *p == ':' || (*p >= '0' && *p <= '9'))
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	write(1, " ", 1);
}

void	ft_print_1n(char *dict, char *n)
{
	char	*p;
	char	*needle;

	needle = malloc(3);
	needle[0] = '1';
	needle[1] = *(n + 1);
	needle[2] = '\0';
	p = ft_strstr(dict, needle);
	while (*p == ' ' || *p == ':' || (*p >= '0' && *p <= '9'))
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	write(1, " ", 1);
}

void	ft_print_n0(char *dict, char *n)
{
	char	*p;
	char	*needle;

	needle = malloc(3);
	needle[0] = *n;
	needle[1] = '0';
	needle[2] = '\0';
	p = ft_strstr(dict, needle);
	while (*p == ' ' || *p == ':' || (*p >= '0' && *p <= '9'))
		p++;
	while (*p != '\n')
		write(1, p++, 1);
	write(1, " ", 1);
}

void	ft_print_nm(char *dict, char *n)
{
	if (n[0] == '0' && n[1] == '0')
		return ;
	if (*n == '1')
		ft_print_1n(dict, n);
	else if (*n == 0)
		ft_print_n(dict, n + 1);
	else
	{
		ft_print_n0(dict, n);
		if (*(n + 1) != '0')
			ft_print_n(dict, n + 1);
	}
}
