/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:24:17 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/13 21:34:26 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*cur_list;
	char			*buff;
	char			*result;
	ssize_t			temp;

	//check list and if had a contents get check and use it 
	buff = 0;
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
	{
		free_all(&list);
		return (0);
	}
	result = 0;
		//if list is exist check fd num and data 
	if (list)
	{
		cur_list = list_checker(&list, fd);
		result = ft_strdup(cur_list->data, ft_strlen(cur_list->data)); // result needed be free
		free(cur_list->data);
		cur_list->data = 0;
	}
	while (1)
	{
		buff = (char *)malloc(BUFFER_SIZE + 1); //need free
		if (!buff)
		{
			if (result)
				free(result);
			return (0);
		}
		temp = read(fd, buff, BUFFER_SIZE);
		if ((!temp && !result) || temp == -1)
		{
			free_all(&list);
			free(buff);
			return (0);
		}
		buff[temp] = 0;
		if (temp && temp != BUFFER_SIZE)
			buff = buffer_re(buff);
		result = ft_strjoin(result, buff);
		if (!result)
		{
			free_all(&list);
			return (0);
		}
		result = buf_check(result, &temp, &list, fd);
		if (!temp || !result)
			return (result);
	}
	return (0);
}

char	*buf_check(char *result, ssize_t *temp, t_list **list, int fd)
{
	size_t	i;

	i = -1;
	while (result[++i])
	{
		if (result[i] == '\n')
		{
			*temp = 0;
			return (fill_list(result, list, i, fd));
		}
	}
	return (result);
}

char	*fill_list(char *result, t_list **list, size_t i, int fd)
{
	char	*ret;
	char	*list_data;
	t_list	*cur;

	ret = ft_strdup(result, i + 1);
	list_data = ft_strdup(result + i + 1,ft_strlen(result) - i - 1 );
	free(result);
	if (!(*list) && list_data)
	{
		*list = (t_list *)malloc(sizeof(t_list));
		(*list)->data = list_data;
		(*list)->next = 0;
		(*list)->fd = fd;
	}
	else if (*list && list_data && ((*list)->fd != fd))
	{
		cur = list_checker(list, -1);
		cur->next = (t_list *)malloc(sizeof(t_list));
		(cur->next)->data = list_data;
		(cur->next)->fd = fd;
		(cur->next)->next = 0;
	}
	else if (*list)
	{
		cur = list_checker(list, fd);
		cur->data = list_data;
	}
	return (ret);
}

void	free_all(t_list **list)
{
	t_list	*temp;
	t_list	*throw;

	temp = *list;
	while (temp)
	{
		if ((temp)->data)
			free((temp)->data);
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

int	free_mal(char *s1, char *s2, char *s3)
{
	if (s1)
	{
		free(s1);
		//*s1 = 0;
	}
	if (s2)
	{
		free(s2);
		//*s2 = 0;
	}
	if (s3)
	{
		free(s3);
		*s3 = 0;
	}
	return (0);
}
char	*buffer_re(char *s)
{
	char	*result;

	result = ft_strdup(s, ft_strlen(s));
	free(s);
	return (result);
}