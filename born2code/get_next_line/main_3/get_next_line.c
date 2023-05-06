/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:16:52 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/14 23:03:24y jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*ret;
	static t_list	*list;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, read, 0) == -1)
	{
		//free_list(&list);
		return (0);
	}
	if (!list)
	{
		list = (t_list *)malloc(sizeof(t_list));
		if (!list)
			return (0);
		list->fd = -1;
		list->next = 0; // head list;
		list->data = NULL;
	}
	ret = buff_read(list_data(&list, fd), &list, fd);
	if (!ret)
		free_list(&list);
	return (ret);
}

void	free_list(t_list **list)
{
	t_list	*throw;
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->data)
			free(temp->data);
		temp = temp->next;
	}
	temp = *list;
	while (temp)
	{
		throw = temp;
		temp = temp->next;
		free(throw);
	}
	*list = 0;
}

char	*buff_read(char *backup, t_list **list, int fd)
{
	char	*buff;
	char	*ret;
	ssize_t	temp;

	buff = 0;
	ret = backup;
	while (1)
	{
		buff = (char *)malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		temp = read(fd, buff, BUFFER_SIZE);
		buff[temp] = 0;
		ret = ft_strjoin(ret, buff);
		if (!ret)
		{
			free(buff);
			return (0);
		}
		if (buff)
			free(buff);
		ret = buff_check(ret, fd, list, &temp);
		if (!temp)
			break;
	}
	return (ret);
}

char	*buff_check(char *ret, int fd, t_list **list, ssize_t *temp)
{
	size_t	i;
	char	*result;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\n')
		{
			list_add(list, fd, ret, i);
			*temp = 0;
			break;
		}
		i++;
	}
	result = ft_strdup(ret, i + 1);
	if (ret)
		free(ret);
	return (result);
}

void	list_add(t_list **list, int fd, char *ret, int i)
{
	t_list *temp;
	char	*list_data;

	temp = *list;
	list_data = ft_strdup(ret + i + 1, ft_strlen(ret));
	while (temp && temp->next)
	{
		if ((temp->next)->fd == fd)
		{
			free((temp->next)->data);
			(temp->next)->data = list_data;
			return ;
		}
		temp = temp->next;
	}
	temp->next = (t_list *)malloc(sizeof(t_list));
	if (!temp->next)
		return ;
	(temp->next)->data = list_data;
	(temp->next)->fd = fd;
}

char	*list_data(t_list **list, int fd)
{
	t_list	*temp;
	char	*result;

	temp = *list;
	result = 0;
	if (temp)
	{
		while (temp)
		{
			if (temp->fd == fd)
				break;
			temp = temp->next;
		}
	}
	else
		return (0);
	if (temp)
	{
		if (temp->data)
			result = temp->data;
	}
	return (result);
}
