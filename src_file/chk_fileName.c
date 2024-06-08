/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_fileName.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:37:45 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 21:49:24 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_filename(int ac, char **ber)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		write(1, "Error\nError in arguments\n", 25);
		exit(1);
	}
	while (ber[1][i])
		i++;
	if (!(ber[1][i - 5]) || ber[1][i - 4] != '.' || ber[1][i - 3] != 'b'
		|| ber[1][i - 2] != 'e' || ber[1][i - 1] != 'r')
	{
		write(1, "Error\n", 7);
		write(1, "Map Extention .ber\n", 20);
		exit(1);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*result;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, (s + start), len + 1);
	return (result);
}

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
