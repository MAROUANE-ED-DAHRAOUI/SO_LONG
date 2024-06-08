/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:38:05 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 21:54:29 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_into_map(char **map, t_info *data)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] != '\0')
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'P')
				data->player_cnt++;
			else if (map[i][j] == 'E')
				data->exit_cnt++;
			else if (map[i][j] == 'C')
				data->coin_cnt++;
		}
	}
	check_all_character(*data);
}

void	cheks_all_map(char **map, t_info *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				free_map(data);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_lines_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] && map[i + 1] != '\0')
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
		{
			ft_printf("error\nlen the lines in map\n");
			exit(1);
		}
	}
}

void	check_border_map(char **map, int i, int j)
{
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
		{
			ft_printf("error\nin map wall\n");
			exit(1);
		}
		j++;
	}
	if (j > 40)
		print_error("Error\nbig map\n");
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i][j] != '1')
		{
			ft_printf("error\nin map wall\n");
			exit(1);
		}
		i++;
	}
	if (i > 21)
		print_error("error\nbig map\n");
	i--;
	check_part_two(map, i);
}

void	check_map(t_info *data)
{
	check_border_map(data->map, 0, 0);
	check_lines_map(data->map);
	check_into_map(data->map, data);
	cheks_all_map(data->map, data);
}
