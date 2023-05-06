/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:47:20 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/11 17:12:56 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (*(str++))
		i++;
	return (i);
}

char *ft_strjoin(char *	s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
		
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	len1 = 0;
	len2 = -1;
	len1 += ft_strlen(s1);
	len1 += ft_strlen(s2);
	result = (char *)malloc(len1 + 1);
	if (!result)
		return (0);
	result[len1] = 0;
	while (s1[++len2])
		result[len2] = s1[len2];
	len1 = -1;
	while (s2[++len1])
		result[len2++]  = s2[len1];
	return (result);
}

size_t	ft_strlen_except(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			break;
		}
		i++;
	}
	return (i);
}

t_string	*list_checker(t_string *list, int fd)
{
	t_string *temp;

	temp = 0;
	temp = list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_string *)malloc(sizeof(t_string));
	return (temp);
}

char	*ft_strdup(char *str, size_t i)
{
	char	*result;
	size_t	k;

	if (!str || !(*str))
		return (0);
	result = (char *)malloc(i + 1);
	if (!result)
		return (0);
	k = 0;
	while(str[k] && k < i)
	{
		result[k] = str[k];
		k++;
	}
	result[k] = 0;
	return (result);
}


// int	ft_lastadd_fd(t_string **list, int fd, char *buf)
// {
// 	size_t	len;
// 	size_t	i;

// 	len = ft_strlen(buf);
// 	i = 0;
// 	if (!(*list))
// 		*list = (t_string *)malloc(sizeof(t_string));
// 	else
// 	{
// 		while ((*list))
// 			*list = (*list)->next;
// 		*list = (t_string *)malloc(sizeof(t_string));
// 	}
// 	if (!(*list))
// 		return (-1);
// 	(*list)->fd = fd;
// 	(*list)->data = (char *)malloc(len + 1); 
// 	if (!(*list)->data)
// 		return (-1);
// 	(*list)->next;
// 	(*list)->data[len] = 0;
// 	while (buf[++i])
// 		(*list)->data[i] = buf[i];
// }