/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujinlee <yujinlee@student.42.seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:29:35 by yujinlee          #+#    #+#             */
/*   Updated: 2023/01/14 11:30:21 by yujinlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int x, int y);


int	main(int argc, char **argv)
{
	int x = 0;
	int y = 0;
	int i = 1;
	int j;
	int result = 0;

	if(argc == 3)
	{
		while(i < argc)
		{
			result = 0;
			j = 0;
			while(argv[i][j] != '\0')
			{
				result *= 10;
				result = result + argv[i][j] - '0';
				j++;
			}	
			if (i == 1)
				x = result;
			else if(i == 2)
				y = result;
			i++;
		}
	}
	rush(x, y);
}
