/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:05:44 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/16 12:34:50 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(null)", 6));
	while (*ptr != '\0')
	{
		ft_putchar((int)*ptr);
		count++;
		ptr++;
	}
	return (count);
}
