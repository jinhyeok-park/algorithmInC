/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:24:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/11 16:29:44 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

typedef struct s_string
{
	int				fd;
	char			*data;
	struct s_string	*next;
} t_string;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif


#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*read_(int fd);
char	*ft_tostatic_add(char *fd_buf, char *buffer, int *flag);
char	*ft_strcat(char *s1, char *s2, size_t size);

char    *get_read(int fd);
char	*buf_fill(char *buf, int len, t_string *list, int fd);
//char	*buf_read(int fd, t_string *list, char buf[BUFFER_SIZE + 1], ssize_t *temp);
//int		list_fill(char *buf, t_string *list, int fd);
char	*get_rest(int fd, t_string *list);
char	*ft_strjoin(char *	s1, char *s2);

size_t	ft_strlen(char *str);
size_t	ft_strlen_except(char *str);
char	*list_fill(char *temp_result, t_string *list, char *buf, size_t i);

t_string	*list_checker(t_string *list, int fd);
char	*ft_strdup(char *str, size_t i);
char *ft_rest_return(t_string *list , size_t i);
char    *buff_read(char *temp_result, char *buf, t_string *list, ssize_t *temp);
#endif