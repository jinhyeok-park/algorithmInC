/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:23:53 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/02 17:03:05 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>

int	ft_warn(int ac)
{
	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	else if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	return (0);
}

int	ft_read(char **av)
{
	int	i;

	i = open(av[1], O_RDONLY);
	if (i == -1)
	{
		write(1, "Cannot read file.\n", 8);
		return (0);
	}
	return (i);
}

void	ft_file_read(int fd)
{
	int		len;
	int		r;
	char	a;

	len = 0;
	while (1)
	{
		r = read(fd, &a, 1);
		write(1, &a, 1);
		if (!r)
			break ;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	if (ft_warn(ac))
		return (0);
	if (!ft_read(av))
		return (0);
	ft_file_read(ft_read(av));
	return (0);
}
