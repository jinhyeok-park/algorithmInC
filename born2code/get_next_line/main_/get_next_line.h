/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:24:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/11 18:13:25 by jinhyeok         ###   ########.fr       */
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

//get_next_line_util.c
t_string	*list_checker(t_string *list, int fd);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *str, size_t i);
char		*ft_strjoin(char *	s1, char *s2);

//get_next_line_.c
char	*get_next_line(int fd);
char	*ft_rest_return(t_string *list , size_t i);
char	*buff_read(char *temp_result, char *buf, t_string *list, ssize_t *temp);
char	*get_rest(int fd, t_string *list);
char	*list_fill(char *temp_result, t_string *list, char *buf, size_t i);
#endif