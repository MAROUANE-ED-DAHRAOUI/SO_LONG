/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:30:10 by med-dahr          #+#    #+#             */
/*   Updated: 2024/06/08 16:30:49 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(const char *ptr)
{
	int		len;
	char	*buffer;

	len = ft_strlen(ptr);
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, ptr, len * sizeof(char) + 1);
	return (buffer);
}
