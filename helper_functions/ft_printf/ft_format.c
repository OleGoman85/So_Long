/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:50:34 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/21 08:00:23 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char *str, size_t *counter)
{
	int	result;

	result = 0;
	if (*str == '%')
		result += ft_putchar_ft('%', counter);
	else if (*str == 'c')
		result += ft_putchar_ft(va_arg(ap, int), counter);
	else if (*str == 's')
		result += ft_putstr_ft(va_arg(ap, char *), counter);
	else if (*str == 'p')
		result += ft_putptr_ft(va_arg(ap, void *), counter);
	else if (*str == 'd' || *str == 'i')
		result += ft_putnbr_ft(va_arg(ap, int), counter);
	else if (*str == 'u')
		result += ft_putuni_ft(va_arg(ap, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			result += ft_puthex_ft(va_arg(ap, unsigned int), counter, HEX_LOW);
		else
			result += ft_puthex_ft(va_arg(ap, unsigned int), counter, HEX_UPP);
	}
	return (result);
}
