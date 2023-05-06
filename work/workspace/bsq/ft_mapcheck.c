/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/01 18:32:26 by sroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_row(char *file)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	len = 0;
	count = 0;
	while (*file != '\n')
		file++;
	file++;
	while (file[len] != '\n')
		len++;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (len != count)
				return (0);
			count = -1;
		}
		count++;
		i++;
	}
	return (len);
}

int	ft_charset_check(char *charset, char *file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i] != '\n')
		i++;
	i++;
	while (file[i])
	{
		j = 0;
		if (file[i] == '\n')
			i++;
		if (!file[i])
			return (1);
		while (charset[j + 1])
		{
			if (charset[j] == file[i])
				break ;
			j++;
		}
		if (!charset[j + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_mapcheck(char *file)
{
	char	*charset;
	int		i;

	i = 0;
	if (ft_check_line(file) && ft_check_num(file) && ft_check_row(file))
	{
		charset = ft_make_charset(file);
		if (ft_check_input(charset) && ft_charset_check(charset, file))
		{
			ft_mapstart(file, charset);
			return (1);
		}
		else
		{
			free(charset);
			return (0);
		}
	}
	else
	{
		return (0);
	}
}

void	ft_mapstart(char *file, char *charset)
{
	t_map	*smap;
	int		*save;
	int		i;

	i = 0;
	smap = ft_make_map1(file, charset);
	ft_change_one(smap);
	save = ft_save_maxpoint(smap);
	ft_change_c_map(smap, save);
	ft_print(smap);
	ft_free(smap);
	free(save);
	free(file);
}
