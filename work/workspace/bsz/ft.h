/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:17:45 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/02/02 12:36:18 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>

//struct
typedef struct s_map
{
	char	**c_map;
	int		**map;
	int		row_size;
	int		col_size;
	char	*charmem;
}	t_map;

//ft_print.c
void	ft_print(t_map *smap);

//ft_makemap.c
t_map	*ft_make_s_map(char *charset);
t_map	*ft_make_map1(char *file, char *charset);
t_map	*ft_make_map2(t_map *smap, int row_len, char *file);
t_map	*ft_init_map(t_map *smap);

//ft_makemap2.c
void	ft_input_data(char *file, t_map *smap);
void	ft_make_charmap(char *file, t_map *smap);
void	ft_make_charmap2(t_map *smap);

//ft_mapcheck.c
int		ft_mapcheck(char *file);
int		ft_check_row(char *file);
int		ft_charset_check(char *charset, char *file);
void	ft_mapstart(char *file, char *charset);

//ft_main.c
int		ft_file_check(char **av);
int		ft_file_len(char **av);
char	*ft_file_read(int fd, int len);
int		ft_check_start(char **av);

//ft_standard_output.c
char	*ft_make_file(void);

//ft_checkchar.c
int		ft_check_num(char *file);
char	*ft_make_charset(char *file);
int		ft_check_input(char *charset);

//ft_change_map.c
t_map	*ft_change_map(t_map *smap);
t_map	*ft_change_one(t_map *smap);
t_map	*ft_change_c_map(t_map *smap, int *save);

//ft_logic.c
int		ft_check_min(t_map *smap, int row, int col);
void	ft_make_squate(t_map *smap);
void	ft_check_max(t_map *smap, int *save);
int		*ft_save_maxpoint(t_map *smap);

//ft_linecheck.c
int		ft_check_line(char *file);

//ft_free.c
void	ft_free(t_map *smap);

//ft_submain.c
void	ft_submain(char **av);

#endif
