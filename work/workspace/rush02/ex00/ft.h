/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:00:19 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/28 13:45:21 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_convert2(char *dict, char *num);
void	ft_converts(char *dict, char *str);
void	ft_convert(char *str);
int		main(int ac, char **av);

int		ft_strlen(char *str);
int		ft_not_good(char *str);
int		ft_atoi(char *str);
int		ft_file_len(int fd);
char	*ft_file_dup(int fd, int file_len);

char	*ft_no_comma(char *num, int j);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_makillion(int num_of_zero);
int		ft_is_alpha(char c);
void	ft_print_sep(char *dict/*, char *n*/, int sep_num);

void	ft_print_nnnv2(char *dict, char *n3, int i);
void	ft_print_nnnv1(char *dict, char *n, int sep_num);

void	ft_print_100(char *dict);
void	ft_print_n(char *dict, char *n);
void	ft_print_1n(char *dict, char *n);
void	ft_print_n0(char *dict, char *n);
void	ft_print_nm(char *dict, char *n);

#endif
