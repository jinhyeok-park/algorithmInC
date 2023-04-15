/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:27:51 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/15 02:43:16 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "get_next_line.h"

// size_t  ft_strlen (char *s1)
// {
//     size_t  i;

//     if (!s1)
//         return (0);
//     while (s1[i])
//         i++;
//     return (i);
// }
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1l;
// 	size_t	s2l;
// 	char	*result;

// 	s1l = ft_strlen(s1);
// 	s2l = ft_strlen(s2);
// 	result = (char *)malloc(s1l + s2l + 1);
// 	if (!result)
// 		return (0);
// 	result[0] = 0;
// 	ft_strlcat(result, (char *)s1, s1l + 1);
// 	ft_strlcat(result, (char *)s2, s1l + s2l + 1);
// 	return (result);
// }

// size_t	ft_strlcat(char *dest, char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	k;
// 	size_t	dest_len;
// 	size_t	src_len;
// 	size_t	result;

// 	i = 0;
// 	k = 0;
// 	dest_len = ft_strlen(dest);
// 	src_len = ft_strlen(src);
// 	result = src_len + dest_len;
// 	if (dest_len > size)
// 		return (src_len + size);
// 	while (dest[i])
// 		i++;
// 	while (src[k] != '\0' && k + dest_len + 1 < size)
// 	{
// 		dest[i] = src[k];
// 		i++;
// 		k++;
// 	}
// 	dest[i] = '\0';
// 	return (result);
// }

// char	*ft_strchr(const char *s, int c)
// {
//     if (!s)
//         return (0);
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*s == (char)c)
// 		return ((char *)s);
// 	return (0);
// }

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

	len1 = ft_strlen(s1);
	len1 += ft_strlen(s2);
	result = (char *)malloc(len1 + 1);
	if (!result)
		return (0);
	result[len1] = 0;
	len2 = 0;
	if (s1)
	{
		len2 = -1;
		while (s1[++len2])
			result[len2] = s1[len2];
	}
	if (s2)
	{
		len1 = -1;
		while (s2[++len1])
		result[len2++] = s2[len1];
	}
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
