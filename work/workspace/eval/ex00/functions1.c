/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heewoopa <heewoopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:01:20 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 12:54:04 by heewoopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define NO 0
#define YES 1

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	ft_is_good(char *str, int *shift, int i, int sign)
{
	if (str == 0) 
		return (NO);
	while (str[i] != 0)
	{
		if ((str[i] == '.') || (str[i] == ' ')
			|| (str[i] == '0')
			|| (str[i] >= 9 && str[i] <= 13))
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -sign;
			i++;
		}
		else if (str[i] >= '1' && str[i] <= '9')
			break ;
		else
			return (NO);
		*shift = *shift + 1;
	}
	return (sign);
}

int	ft_file_len(int fd) /* edit */
{
	int		i;
	int		r;
	char	a;

	r = 1;
	i = 0;

	while (r == 1)
	{
		r = read(fd, &a, 1);
		i++;
	}
	close(fd);
	return (i);
}

char    *ft_file_dup(int fd, int file_len) /* edit */
{
    char    *d;
    d = malloc(file_len + 1);
    read(fd, d, file_len);
    d[file_len] = '\0';
    close(fd);
    return (d);
}
