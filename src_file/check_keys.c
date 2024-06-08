/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:37:32 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 16:55:06 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_info *data)
{
	if (data->map)
		ft_freestr(data->map);
	if (data->map_cpy)
		ft_freestr(data->map_cpy);
}

void	move_up(t_info *data)
{
	if (data->map_cpy[data->pl_x - 1][data->pl_y] == 'E')
	{
		if (data->coin_cnt == 0)
		{
			free_map(data);
			exit(1);
		}
	}
	else if (data->map_cpy[data->pl_x - 1][data->pl_y] != '1')
	{
		if (data->map_cpy[data->pl_x - 1][data->pl_y] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
				(data->pl_y) * 64, (data->pl_x - 1) * 64);
			data->map_cpy[data->pl_x - 1][data->pl_y] = '0';
			data->coin_cnt--;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
			(data->pl_y) * 64, (data->pl_x - 1) * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->pl_y) * 64, (data->pl_x) * 64);
		ft_printf("count move : %d\n", ++data->mv);
		data->pl_x--;
	}
}

void	move_left(t_info *data)
{
	if (data->map_cpy[data->pl_x][data->pl_y - 1] == 'E')
	{
		if (data->coin_cnt == 0)
		{
			free_map(data);
			exit(0);
		}
	}
	else if (data->map_cpy[data->pl_x][data->pl_y - 1] != '1')
	{
		if (data->map_cpy[data->pl_x][data->pl_y - 1] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
				(data->pl_y - 1) * 64, (data->pl_x) * 64);
			data->map_cpy[data->pl_x][data->pl_y - 1] = '0';
			data->coin_cnt--;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
			(data->pl_y - 1) * 64, (data->pl_x) * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->pl_y) * 64, (data->pl_x) * 64);
		ft_printf("count move : %d\n", ++data->mv);
		data->pl_y--;
	}
}

void	move_down(t_info *data)
{
	if (data->map_cpy[data->pl_x + 1][data->pl_y] == 'E')
	{
		if (data->coin_cnt == 0)
		{
			free_map(data);
			exit(0);
		}
	}
	else if (data->map_cpy[data->pl_x + 1][data->pl_y] != '1')
	{
		if (data->map_cpy[data->pl_x + 1][data->pl_y] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
				(data->pl_y) * 64, (data->pl_x + 1) * 64);
			data->map_cpy[data->pl_x + 1][data->pl_y] = '0';
			data->coin_cnt--;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
			(data->pl_y) * 64, (data->pl_x + 1) * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->pl_y) * 64, (data->pl_x) * 64);
		ft_printf("count move : %d\n", ++data->mv);
		data->pl_x++;
	}
}

void	move_right(t_info *data)
{
	if (data->map_cpy[data->pl_x][data->pl_y + 1] == 'E')
	{
		if (data->coin_cnt == 0)
		{
			free_map(data);
			exit(0);
		}
	}
	else if (data->map_cpy[data->pl_x][data->pl_y + 1] != '1')
	{
		if (data->map_cpy[data->pl_x][data->pl_y + 1] == 'C')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
				(data->pl_y + 1) * 64, (data->pl_x) * 64);
			data->map_cpy[data->pl_x][data->pl_y + 1] = '0';
			data->coin_cnt--;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
			(data->pl_y + 1) * 64, (data->pl_x) * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
			(data->pl_y) * 64, (data->pl_x) * 64);
		ft_printf("count move : %d\n", ++data->mv);
		data->pl_y++;
	}
}
