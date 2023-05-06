/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:11:10 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/01 12:37:30 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_make_file(void)
{
	int		fd;
	char	*buf;

	fd = open("ft_input", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (NULL);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
	return ("ft_input");
}
