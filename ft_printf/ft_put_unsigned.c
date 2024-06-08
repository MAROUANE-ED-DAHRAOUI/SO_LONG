/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:19:55 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/16 12:03:30 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_put_unsigned(nb / 10);
	count += ft_putchar((nb % 10) + 48);
	return (count);
}
