/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:58:57 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/18 11:51:05 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_cleanup(va_list ap, int result)
{
	va_end(ap);
	return (result);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	size_t	counter;

	if (!format)
		return (-1);
	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_format(ap, (char *)format, &counter) == -1)
				return (ft_printf_cleanup(ap, -1));
		}
		else
		{
			if (ft_putchar_ft(*format, &counter) == -1)
				return (ft_printf_cleanup(ap, -1));
		}
		format++;
	}
	return (ft_printf_cleanup(ap, counter));
}
