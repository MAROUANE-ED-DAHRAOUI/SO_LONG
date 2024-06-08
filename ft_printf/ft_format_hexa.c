/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:35:18 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/16 12:51:10 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printed_hexa(unsigned long nb, int base)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		count += ft_putchar("0123456789abcdef"[nb]);
	}
	else
	{
		count += printed_hexa(nb / base, base);
		count += printed_hexa(nb % base, base);
	}
	return (count);
}

int	ft_format_hexa(unsigned long var)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += printed_hexa(var, 16);
	return (count);
}
