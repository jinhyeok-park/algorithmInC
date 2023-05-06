/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:56:36 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/10 10:57:24by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_sizecheck(int fd, char *result, int *flag);
char    *get_read(int fd);

char	*get_next_line(int fd)
{
	if (fd == -1)
		return (0);
	get_read(fd);
	return(0);
	
}
char    *get_read(int fd)
{
	size_t	i;
	int		flag;
	char	*result;
	static	char	*rest;

	i = 0;
	flag = 0;
	result = NULL;
	int	k = 0;
	if (rest)
		buff_rest(rest);

	while (1)
	{
		result = buff_sizecheck(fd, result, &flag);
		if (flag)
			break;


	}
	return (0);

}
char	*buff_rest(char *rest)
{
	size_t	len;
	char	*result;

	len = 0;
	while (rest[len])
		len++;
	result = (char *)malloc(len + 1);
	result[len] = 0;
	len = 0;
	while (rest)
	{
		result[len] = result[len];
	}
	return (result);
}

char	*buff_sizecheck(int fd, char *result, int *flag)
{
	int	temp;
	char	temp_buffer[BUFFER_SIZE + 1];
	int	i;

	temp = read(fd ,temp_buffer, (size_t)BUFFER_SIZE);
	temp_buffer[BUFFER_SIZE] = 0 ;
	i = 0;
	int	k = 0;
	while (i < temp)
	{
		if (temp_buffer[i++] == '\n')
		{
			*flag = i;
			break;
		}
	}


return (0);

}

//char	*buff_check(char *buf, )