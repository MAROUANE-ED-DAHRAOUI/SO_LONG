/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:39:25 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/16 13:24:49 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upper_hexa(unsigned int nb, int base)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		count += ft_putchar("0123456789ABCDEF"[nb]);
	}
	if (nb >= 16)
	{
		count += ft_upper_hexa(nb / base, base);
		count += ft_putchar("0123456789ABCDEF"[nb % base]);
	}
	return (count);
}
