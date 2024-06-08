/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:38:24 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 16:52:17 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_player_position(t_info *data, int *pl_row, int *pl_colun)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				*pl_row = i;
				*pl_colun = j;
			}
			j++;
		}
		i++;
	}
	data->pl_x = *pl_row;
	data->pl_y = *pl_colun;
}

void	flood_fill(t_info *data, int x, int y)
{
	chk_flood_fill(data, x - 1, y);
	chk_flood_fill(data, x + 1, y);
	chk_flood_fill(data, x, y - 1);
	chk_flood_fill(data, x, y + 1);
}

int	chk_flood_fill(t_info *data, int x, int y)
{
	if (data->map[x][y] == 'P')
	{
		data->map[x][y] = 'X';
		flood_fill(data, x, y);
	}
	else if (data->map[x][y] == 'E')
	{
		data->map[x][y] = 'X';
		data->exit_cnt--;
	}
	else if (data->map[x][y] == 'C')
	{
		data->map[x][y] = 'X';
		data->cnt++;
		flood_fill(data, x, y);
	}
	else if (data->map[x][y] == '0')
	{
		data->map[x][y] = 'X';
		flood_fill(data, x, y);
	}
	if (data->exit_cnt == 0 && data->coin_cnt == data->cnt)
		return (0);
	return (1);
}
