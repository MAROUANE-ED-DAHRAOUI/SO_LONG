/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:38:16 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 21:58:37 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_win(t_info *map)
{
	(void)map;
	free_map(map);
	exit(0);
}

void	initialize_game(t_info *data)
{
	data->image_height = 64;
	data->image_width = 64;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->width * 64, data->height
			* 64, "so_long");
	data->img_coin = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm",
			&data->image_width, &data->image_height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm",
			&data->image_width, &data->image_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&data->image_width, &data->image_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
			&data->image_width, &data->image_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&data->image_width, &data->image_height);
	if (!(data->img_coin) || !(data->img_floor) || !(data->img_exit)
		|| !(data->img_player) || !(data->img_wall))
		print_error("error\nError in img_...\n");
	mlx_clear_window(data->mlx, data->mlx_win);
	watch_gamess(data, -1, -1);
	mlx_key_hook(data->mlx_win, fun_keys, data);
	mlx_hook(data->mlx_win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
}

void	put_image(t_info *data, void *img, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, 
		data->img_floor, (j * 64), (i * 64));
	mlx_put_image_to_window(data->mlx, data->mlx_win, 
		img, (j * 64), (i * 64));
}

void	watch_gamess(t_info *data, int i, int j)
{
	while (data->map_cpy[++i])
	{
		j = -1;
		while (data->map_cpy[i][++j] != '\0')
		{
			if (data->map_cpy[i][j] == 'P')
				put_image(data, data->img_player, i, j);
			else if (data->map_cpy[i][j] == 'C')
				put_image(data, data->img_coin, i, j);
			else if (data->map_cpy[i][j] == 'E')
				put_image(data, data->img_exit, i, j);
			else if (data->map_cpy[i][j] == '1')
				put_image(data, data->img_wall, i, j);
			else if (data->map_cpy[i][j] == '0')
				put_image(data, data->img_floor, i, j);
		}
	}
}

int	fun_keys(int keycode, t_info *data)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_up(data);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(data);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(data);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(data);
	return (0);
}
