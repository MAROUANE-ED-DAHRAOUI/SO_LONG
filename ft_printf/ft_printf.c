/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:16:26 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/19 15:36:42 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(va_list ap, char value)
{
	int	count;

	count = 0;
	if (value == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (value == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (value == 'd' || value == 'i')
		count += ft_putnbr((long)va_arg(ap, int), 10);
	else if (value == 'u')
		count += ft_put_unsigned(va_arg(ap, unsigned int));
	else if (value == 'p')
		count += ft_format_hexa((unsigned long)va_arg(ap, void *));
	else if (value == 'x')
		count += ft_lower_hexa(va_arg(ap, unsigned int), 16);
	else if (value == 'X')
		count += ft_upper_hexa(va_arg(ap, unsigned int), 16);
	else if (value == '%')
		count += ft_putchar('%');
	else
		count += write(1, &value, 1);
	return (count);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, ptr);
	while (*ptr != '\0')
	{
		if (*ptr == '%' && *(ptr + 1) != '\0')
			count += check_format(ap, *(++ptr));
		else if (*ptr != '%')
			count += write(1, ptr, 1);
		ptr++;
	}
	va_end(ap);
	return (count);
}
