/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:13:40 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/11 11:54:02 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_string list;
	char	buf[BUFFER_SIZE + 1];
	char	*result;
	char	*buff_temp;
	ssize_t		temp;

	result = 0;
	buff_temp = NULL;
	if (fd < 0)
		return (0);
	result = get_rest(fd, &list);
	if (result)
	{
		list.next = (t_string *)malloc(sizeof(t_string));
		list = *list.next;
	}
	while (1)
	{
		temp = ft_strlen(result);
		buff_temp = buf_read(fd, &list, result, &temp);
		if (temp == -1)
		{
			free(result);
			return (buff_temp);
		}
		temp = read(fd, buf, BUFFER_SIZE);
		buf[temp] = 0;
		buff_temp = buf_read(fd, &list, buf, &temp);
		result = ft_strjoin(result, buff_temp);
		if (!buff_temp || temp == -1 || !temp)
			return (result);
	}
	return (result);
}

char	*buf_read(int fd, t_string *list, char *buf, ssize_t *temp)
{
	char	*result;
	ssize_t	i;
	ssize_t len_temp;

	if (!*temp)
		return (0);
	len_temp = *temp;
	i = 0;
	if (*temp < 0)
		return (0);
	while (i < len_temp)
	{
		if (buf[i++] == '\n')
		{
			result = buf_fill(buf, i, list, fd);
			*temp = -1;
			break;
		}
	}
	if (i == len_temp)
		result = buf_fill(buf, i + 1, NULL, fd);
	return (result);
}

int	list_fill(char *buf, t_string *list, int fd)
{
	size_t	len;
	size_t	i;
	t_string *temp_list;

	temp_list = list;
	len = ft_strlen(buf);
	i = -1;
	if (temp_list->fd)
	{
		while (temp_list->next)
			temp_list = temp_list->next;
		temp_list->next = (t_string *)malloc(sizeof(t_string));
		if (!temp_list->next)
			return (-1);
		temp_list = temp_list->next;
	}
	temp_list->fd = fd;
	temp_list->data = (char *)malloc(len + 1); 
	if (!(temp_list->data))
		return (-1);
	temp_list->data[len] = 0;
	while (buf[++i])
		temp_list->data[i] = buf[i];
	return (1);
}

char	*buf_fill(char *buf, int len, t_string *list, int fd)
{
	int	i;
	int	buf_len;
	char	*result;

	i = -1;
	buf_len = ft_strlen(buf);
	result = (char *)malloc(len);
	if (!result)
		return (0);
	while (++i + 1 < len)
		result[i] = buf[i];
	result[i] = 0;
	if (buf_len != len && list)
		list_fill(buf + len, list, fd);
	return (result);
}

char	*get_rest(int fd, t_string *list)
{
	size_t	len;
	size_t	i;
	t_string *temp;
	char	*str;
	char	*result;

	temp = list;
	str = 0;
	if (!(temp->fd))
		return (0);
	while (temp)
	{
		if (temp->fd == fd)
			{
				str = temp->data;
				break;
			}
		temp = temp->next;
	}
	if (!str)
		return (0);
	i = -1;
	len = ft_strlen_except(str);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	while (++i < len)
		result[i] = str[i];
	return (result);
}

