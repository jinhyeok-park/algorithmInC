/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:56:53 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/13 08:58:21 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i ++;
	}
}

int	ft_check_char(char ch)
{
	if (ch < 48 || (ch > 57 && ch < 65))
		return (1);
	if ((ch > 90 && ch < 97) || ch > 122)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_lowercase(str);
	while (str[i])
	{
		if (ft_check_char(str[i]) && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
				str[i + 1] -= 32;
		else if (str[i] >= 'a' && str[i] <= 'z' && i == 0)
			str[i] -= 32;
		i++;
	}
	return (str);
}
