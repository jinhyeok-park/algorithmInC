/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:47:20 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/12 19:36:31 by jinhyeok         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s2)
		return (ft_strdup(s1, ft_strlen(s1)));
	if (!s1)
		return (ft_strdup(s2, ft_strlen(s2)));
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
		result[len2++] = s2[len1];
	return (result);
}

t_list	*list_checker(t_list *list, int fd)
{
	t_list	*temp;

	temp = 0;
	temp = list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_list *)malloc(sizeof(t_list));
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
	while (str[k] && k < i)
	{
		result[k] = str[k];
		k++;
	}
	result[k] = 0;
	return (result);
}
