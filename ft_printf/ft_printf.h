/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <med-dahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:43:44 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/16 14:58:17 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *ptr, ...);
int		ft_putchar(char c);
int		ft_putstr(char *ptr);
int		ft_putnbr(long nb, int base);
int		ft_put_unsigned(unsigned int nb);
int		ft_format_hexa(unsigned long var);
int		ft_lower_hexa(unsigned int nb, int base);
int		ft_upper_hexa(unsigned int nb, int base);
#endif
