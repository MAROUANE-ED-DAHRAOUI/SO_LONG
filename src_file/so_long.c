/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:37:08 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 21:50:40 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	exit(1);
}

void	ft_freestr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*concat(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

void	read_map(t_info *data, int fd)
{
	char	*str1;
	char	*str3;

	str3 = ft_strdup("");
	str1 = get_next_line(fd);
	if (!str1 || str1[0] == '\n')
		print_error("Error\nread map!\n");
	while (str1 != NULL)
	{
		str3 = concat(str3, str1);
		free(str1);
		str1 = get_next_line(fd);
	}
	ft_check_new_line(str3);
	free(str1);
	data->map = ft_split(str3, '\n');
	data->map_cpy = ft_split(str3, '\n');
	free(str3);
	if (!data->map)
		print_error("error\nin map\n");
}
void ttyt()
{
	system("leaks -q so_long");
}

int	main(int ac, char **av)
{
	t_info	*data;
	int		pl_row;
	int		pl_colun;
	int		fd;

	atexit(ttyt);
	if (ac != 2)
		exit(1);
	data = ft_calloc(1, sizeof(t_info));
	if (!data)
		print_error("error\nError in data\n");
	ft_check_filename(ac, av);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		print_error("error\nError in fd\n");
	init_info(data, fd);
	check_map(data);
	ft_player_position(data, &pl_row, &pl_colun);
	if (chk_flood_fill(data, pl_row, pl_colun))
		print_error("error\nin map5\n");
	initialize_game(data);
	system("leaks ./so_long");

}
