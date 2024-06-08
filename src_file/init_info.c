/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:37:54 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 21:52:26 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_info(t_info *data, int fd)
{
	int	i;

	read_map(data, fd);
	data->width = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
		i++;
	data->height = i;
	if (data->height < 3)
		print_error("Errore\nin hieght_cnt\n");
}

void	ft_check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("error\nin new line awld nas\n");
			exit(1);
		}
		i++;
	}
	if (i && str[i - 1] == '\n')
	{
		ft_printf("error\nin new line awld nas\n");
		exit(1);
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}

void	check_all_character(t_info data)
{
	if (data.player_cnt != 1 || data.exit_cnt != 1 || data.coin_cnt < 1)
		print_error("error\nchi player zayd wla exit wla coin < 1\n");
}

void	check_part_two(char **map, int i)
{
	int		j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
		{
			ft_printf("error\nin map wall\n");
			exit(1);
		}
		j++;
	}
	j--;
	while (map[i--] && i >= 0)
	{
		if (map[i][j] != '1')
		{
			ft_printf("error\nin map wall\n");
			exit(1);
		}
	}
}
