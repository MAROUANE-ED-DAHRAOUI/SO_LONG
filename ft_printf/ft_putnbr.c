/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:05:27 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/18 13:14:27 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prints_nbr(long nb, int base)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < base)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		prints_nbr(nb / base, base);
		ft_putchar((nb % 10) + 48);
	}
}

int	ft_putnbr(long nb, int base)
{
	int			count;
	long int	nbrr;

	count = 0;
	nbrr = nb;
	prints_nbr(nb, base);
	if (nbrr == 0)
		return (1);
	if (nbrr < 0)
	{
		nbrr *= -1;
		count++;
	}
	while (nbrr > 0)
	{
		nbrr /= base;
		count++;
	}
	return (count);
}
