/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeok <jungyeok@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:00:19 by jungyeok          #+#    #+#             */
/*   Updated: 2023/01/29 23:04:08 by jungyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_dot(char *n);
void	ft_convert2(char *dict, char *num, int s);
void	ft_converts(char *dict, char *str);
void	ft_convert(char *str);
int		main(int ac, char **av);

int		ft_strlen(char *str);
int		ft_error(char *str);
int		ft_not_good(char *str, int *shift, int i, int s);
int		ft_file_len(int fd);
char	*ft_file_dup(int fd, int file_len);

char	*ft_strstr(char *haystack, char *needle);
char	*ft_makillion(int num_of_zero);
void	ft_print_sep(char *dict, char *n, int sep_num);

void	ft_start(int r);
void	ft_print_nnnv3(char *dict, char *n3, int i, int sep_num);
void	ft_print_nnnv2(char *dict, char *n3, int i, int sep_num);
void	ft_print_nnnv1(char *dict, char *n, int sep_num);
int		ft_too_long(int n_len, char *dict);

void	ft_print_100(char *dict, char *n3);
void	ft_print_n(char *dict, char *n, int sep_num);
void	ft_print_1n(char *dict, char *n, int sep_num);
void	ft_print_n0(char *dict, char *n, int sep_num);
void	ft_print_nm(char *dict, char *n, int sep_num);

#endif
