/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:08:28 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/21 07:18:45 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_digit(int digit, size_t *counter)
{
	char	hex_char;

	if (digit < 0 || digit > 15)
		return (-1);
	if (digit < 10)
		hex_char = digit + '0';
	else
		hex_char = digit - 10 + 'a';
	if (write(1, &hex_char, 1) != 1)
		return (-1);
	(*counter)++;
	return (0);
}

static int	print_value_as_hex(uintptr_t value, size_t *counter)
{
	if (value >= 16)
	{
		if (print_value_as_hex(value / 16, counter) == -1)
			return (-1);
	}
	if (print_hex_digit(value % 16, counter) == -1)
		return (-1);
	return (0);
}

int	ft_putptr_ft(void *ptr, size_t *counter)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (write(1, "0x", 2) != 2)
		return (-1);
	*counter += 2;
	if (print_value_as_hex(address, counter) == -1)
		return (-1);
	return (0);
}
