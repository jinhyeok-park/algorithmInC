/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:45:37 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/02 17:29:12 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_file_check(char **av)
{
	int	fd;

	fd = 0;
	fd = open(av[0], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	return (fd);
}

int	ft_file_len(char **av)
{
	int		len;
	int		r;
	char	a;
	int		fd;

	fd = ft_file_check(av);
	len = 0;
	r = 1;
	while (r)
	{
		r = read(fd, &a, 1);
		if (!r)
			break ;
		len++;
	}
	close(fd);
	return (len);
}

char	*ft_file_read(int fd, int len)
{
	int		i;
	int		r;
	char	a;
	char	*file;

	i = 0;
	r = 1;
	file = (char *)malloc(len + 1);
	while (r)
	{
		r = read(fd, &a, 1);
		if (!r)
			break ;
		file[i] = a;
		i++;
	}
	file[i] = '\0';
	close(fd);
	return (file);
}

int	ft_check_start(char **av)
{
	int		len;
	int		fd;
	char	*file;

	len = ft_file_len(av);
	if (len < 4)
		return (0);
	fd = ft_file_check(av);
	file = ft_file_read(fd, len);
	if (!ft_mapcheck(file))
	{
		free(file);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*newfile;

	if (ac == 1)
	{
		newfile = ft_make_file();
		av = (char **)malloc(sizeof(char *));
		*av = newfile;
		ft_submain(av);
		free(av);
	}
	while (--ac)
	{
		av++;
		ft_submain(av);
		if (ac != 1)
			write(1, "\n", 1);
	}
	return (0);
}
