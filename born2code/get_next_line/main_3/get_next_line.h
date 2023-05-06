/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:24:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/04/15 03:30:41 by jinhyeok         ###   ########.fr       */
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
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
t_list	*list_checker(t_list *list, int fd);
char	*ft_strdup(char *str, size_t i);
char	*get_next_line(int fd);
void	free_list(t_list **list);
char	*buff_read(char *backup, t_list **list, int fd);
char	*buff_check(char *ret, int fd, t_list **list, ssize_t *temp);
void	list_add(t_list **list, int fd, char *ret, int i);
char	*list_data(t_list **list, int fd);

#endif