/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:01:20 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 23:02:18 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
				|| str[i] == '+' || str[i] == '-' || str[i] == ','))
			return (1);
		i++;
	}
	return (0);
}

int	ft_not_good(char *str, int *shift, int i, int s)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] == '0')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		*shift = i;
	else
		*shift = i - 1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
		str[i] = '\0';
	return (s);
}

int	ft_file_len(int fd)
{
	int		i;
	int		r;
	char	a;

	r = 1;
	i = 0;
	while (r)
	{
		r = read(fd, &a, 1);
		if (!r)
			break ;
		i++;
	}
	close(fd);
	return (i);
}

char	*ft_file_dup(int fd, int file_len)
{
	char	*d;
	char	a;
	int		i;
	int		r;

	d = malloc(file_len + 2);
	r = 1;
	d[0] = '\n';
	i = 1;
	while (r)
	{
		r = read(fd, &a, 1);
		if (!r)
			break ;
		d[i] = a;
		i++;
	}
	d[i] = '\0';
	close(fd);
	return (d);
}
