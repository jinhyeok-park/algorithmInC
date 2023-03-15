/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:37:19 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/03/15 19:47:03 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen(s1);
	start = 0;
	end = 0;
	i = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strrchr(set, s1[end]))
		end++;
	result = (char *)malloc(len - start - end + 3);
	result[len - start - end + 3] = '\0';
	while (start < len)
	{
		result[i++] = s1[start];
		start++;
	}
	return (result);
}

int main(void)
{
	char arr[130] = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n";
	//char arrr[10] = "aabbbaba";
	char arr1[10] = " \n\t";
	printf("%s\n", ft_strtrim(arr,arr1));
}
