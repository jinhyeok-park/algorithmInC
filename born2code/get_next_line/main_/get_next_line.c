/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:36:22 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/12 15:04:08by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	list;
	//char			buf[BUFFER_SIZE + 1];
	char			*result;
	char			*temp_result;
	ssize_t			temp;
	//char			*buf;

	result = 0;
	if (fd < 0 || read(fd, result, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (list.fd)
		list = *list_checker(&list, fd);
	result = get_rest(&list);
	if (result)
		return (result);
	temp_result = ft_strdup(list.data, BUFFER_SIZE);
	list.fd = fd;
	while (1)
	{
		result = (char *)malloc(BUFFER_SIZE + 1);
		temp = read(fd, result, BUFFER_SIZE);
		result[temp] = 0;
		temp_result = buff_read(temp_result, result, &list, &temp);
		if (result)
		{
			free(result);
			result = 0;
		}

		// buf[temp] = 0;
		// temp_result = buff_read(temp_result, buf, &list, &temp);
		if (!temp)
			return (temp_result);
	}
	return (result);
}

char	*buff_read(char *temp_result, char *buf, t_list *list, ssize_t *temp)
{
	size_t	i;
	size_t	byte;
	char	*result;

	i = 0;
	result = 0;
	if (!*temp)
		return (temp_result);
	byte = (size_t)(*temp);
	while (i < byte)
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
	temp_result = 0;
	if (byte < BUFFER_SIZE)
		*temp = 0;
	return (result);
}

char	*list_fill(char *temp_result, t_list *list, char *buf, size_t i)
{
	char	*result;
	char	*temp_list;
	char	*temp;
	size_t	len;

	len = ft_strlen(buf);
	temp = ft_strdup(buf, i + 1);
	temp_list = ft_strdup(buf + i + 1, len - i);
	result = ft_strjoin(temp_result, temp);
	free(temp);
	free(temp_result);
	if (list->data)
		free(list->data);
	list->data = temp_list;
	return (result);
}

char	*get_rest(t_list *list)
{
	t_list	*temp_list;
	size_t		i;
	char		*result;

	temp_list = list;
	result = 0;
	if (!list->fd || !(list->data))
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

char	*ft_rest_return(t_list *list, size_t i)
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
