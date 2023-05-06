/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:24:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/13 20:57:41 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*data;
	struct s_list	*next;
	struct s_list	*before;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
//get_next_line_util.c
t_list	*list_checker(t_list **list, int fd);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *str, size_t i);
char		*ft_strjoin(char *s1, char *s2);
//get_next_line_.c
char		*get_next_line(int fd);
char		*ft_rest_return(t_list *list, size_t i);
char		*buff_read(char *temp_result, char *buf, \
t_list *list, ssize_t *temp);
char		*get_rest(t_list *list);
char		*list_fill(char *temp_result, t_list *list, char *buf, size_t i);


char	*buf_check(char *result, ssize_t *temp, t_list **list, int fd);
char	*fill_list(char *result, t_list **list, size_t i, int fd);
void	free_all(t_list **list);
int		free_mal(char *s1, char *s2, char *s3);
char	*buffer_re(char *s);

#endif