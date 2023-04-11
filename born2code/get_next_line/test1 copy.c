/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:36:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/11 13:29:51y jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*get_next_line(int fd)
{
	static t_string list;
	char    buf[BUFFER_SIZE + 1];
	char    *result;
	char	*temp_result;
	ssize_t	temp;

	result = 0;
	if (list.fd)
		list = *list_checker(&list, fd);
	result = get_rest(fd, &list);
	if (result)
		return (result);
	temp_result = ft_strdup(list.data, BUFFER_SIZE);
	list.fd = fd;
	while (1)
	{
		temp = read(fd, buf, BUFFER_SIZE);
		buf[temp] = 0;
		temp_result = buff_read(temp_result, buf, &list, &temp);
		if (!temp)
			return (temp_result);
	}
	return (result);
}

char    *buff_read(char *temp_result, char *buf, t_string *list, ssize_t *temp)
{
	size_t	i;
	char	*result;

	i = 0;
	result = 0;
	while (i < *temp)
	{
		if (buf[i] == '\n')
		{
			*temp = 0;
			result = list_fill(temp_result, list, buf, i);
			return (result);
		}
		i++;
	}
	result = ft_strjoin(temp_result, buf);
	free(temp_result);
	return (result);
}

char	*list_fill(char *temp_result, t_string *list, char *buf, size_t i)
{
	char	*result;
	char	*temp_list;
	char	*temp;
	size_t	len;
	size_t	k;

	len = ft_strlen(buf);
	temp = ft_strdup(buf, i);
	temp_list = ft_strdup(buf + i + 1, len - i);
	result = ft_strjoin(temp_result, temp);
	free(temp);
	free(temp_result);
	if (list->data)
		free(list->data);
	list->data = temp_list;
	return (result);
}

char    *get_rest(int fd, t_string *list)
{
	//if list has a many \n   ex) 23\n3\n23\n . read 10 bit;
	// if the rest be, toss it read_check sentence
	t_string    *temp_list;
	size_t		i;
	char        *result;

	temp_list = list;
	result = 0;
	if (!list->fd)// first time, dont have a data
		return (0);
	i = 0;
	while (temp_list->data[i])
	{
		if (temp_list->data[i] == '\n')
			return (ft_rest_return(temp_list, i));
		i++;
	}
	return (0);
}

char *ft_rest_return(t_string *list , size_t i)
{
	char	*result;
	char	*list_result;

	result = ft_strdup(list->data, i);
	list_result = ft_strdup(list->data + i + 1, BUFFER_SIZE);
	free(list->data);
	if (!list_result)
	{
		list->fd = 0;
		list->data = 0;
	}
	else
		list->data = list_result;
	return (result);
}