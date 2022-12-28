/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:37:09 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 01:42:09 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "rush02.h"

int	init_dict(t_dict *dict)
{
	int	i;

	dict->fd = -1;
	dict->thousands_size = 13;
	dict->ones = (char **)malloc(sizeof(char *) * 10);
	dict->teens = (char **)malloc(sizeof(char *) * 10);
	dict->tens = (char **)malloc(sizeof(char *) * 10);
	dict->hundred = 0;
	dict->thousands = (char **)malloc(sizeof(char *) * 13);
	if (!(dict->ones) || !(dict->teens) || !(dict->tens) || !(dict->thousands))
		return (0);
	i = 0;
	while (i < 12)
	{
		if (i < 10)
		{
			dict->ones[i] = 0;
			dict->teens[i] = 0;
			dict->tens[i] = 0;
		}
		dict->thousands[i] = 0;
		i++;
	}
	return (1);
}

int	read_dict(t_dict **dict, char *filename)
{
	int		fd;
	int		res;

	res = 0;
	*dict = (t_dict *)malloc(sizeof(t_dict));
	if (!*dict)
		return (0);
	if (!init_dict(*dict))
		return (0);
	fd = open(filename, 0);
	(*dict)->fd = fd;
	if (fd < 0)
		return (res);
	res = read_file(fd, *dict);
	close(fd);
	return (res);
}

int	check_dict(t_dict *dict)
{
	int	i;

	if (dict->fd < 0)
		return (0);
	if (dict->hundred == 0)
		return (0);
	i = 0;
	while (i < dict->thousands_size)
	{
		if (i < 10 && (dict->ones[i] == 0 || dict->teens[i] == 0))
			return (0);
		if (i > 1 && i < 10 && dict->tens[i] == 0)
			return (0);
		if (i > 0 && dict->thousands[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	if (dict->hundred != 0)
		free(dict->hundred);
	while (i < dict->thousands_size)
	{
		if (i < 10 && dict->ones[i] != 0)
			free(dict->ones[i]);
		if (i < 10 && dict->teens[i] != 0)
			free(dict->teens[i]);
		if (i > 1 && i < 10 && dict->tens[i] != 0)
			free(dict->tens[i]);
		if (i > 0 && dict->thousands[i] != 0)
			free(dict->thousands[i]);
		i++;
	}
	free(dict->ones);
	free(dict->teens);
	free(dict->tens);
	free(dict->thousands);
	free(dict);
}
