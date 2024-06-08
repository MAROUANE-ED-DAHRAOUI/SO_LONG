/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:37:23 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 20:56:56 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../minilibx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct info
{
	int		pl_x;
	int		pl_y;
	int		steps;
	char	**map;
	char	**map_cpy;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	int		image_height;
	int		image_width;
	char	*floor;
	char	*player;
	char	*coin;
	char	*exit;
	char	*wall;
	int		coin_cnt;
	int		exit_cnt;
	int		player_cnt;
	int		wall_cnt;
	int		space_cnt;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_coin;
	int		cnt;
	int		mv;

}			t_info;

void		print_error(char *str);
void		read_map(t_info *data, int fd);
void		ft_check_filename(int ac, char **ber);
void		cheks_all_map(char **map, t_info *data);
void		check_lines_map(char **map_line);
void		check_border_map(char **map, int i, int j);
void		check_into_map(char **map, t_info *data);
void		check_all_character(t_info data);
void		init_info(t_info *data, int fd);
void		check_map(t_info *data);
void		ft_player_position(t_info *data, int *pl_row, int *pl_colun);
void		ft_freestr(char **str);
void		flood_fill(t_info *data, int x, int y);
int			chk_flood_fill(t_info *data, int x, int y);
char		*ft_strdup(const char *ptr);
char		**ft_split(char const *str, char dil);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, int len);
char		*concat(char *s1, char *s2);

// game
void		initialize_game(t_info *data);
void		watch_gamess(t_info *data, int i, int j);
int			fun_keys(int keycode, t_info *data);
void		move_up(t_info *data);
void		move_left(t_info *data);
void		move_down(t_info *data);
void		move_right(t_info *data);
void		free_map(t_info *data);
void		ft_check_new_line(char *str);
void		check_part_two(char **map, int i);

#endif