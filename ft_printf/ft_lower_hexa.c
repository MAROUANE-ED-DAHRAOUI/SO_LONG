/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:21:23 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/18 13:05:40 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lower_hexa(unsigned int nb, int base)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		count += ft_putchar("0123456789abcdef"[nb]);
	}
	if (nb >= 16)
	{
		count += ft_lower_hexa(nb / base, base);
		count += ft_putchar("0123456789abcdef"[nb % base]);
	}
	return (count);
}
