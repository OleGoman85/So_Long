/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:38:46 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/21 07:59:30 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ft(unsigned int num, size_t *counter, int letter_case)
{
	if (num >= 16)
	{
		if (ft_puthex_ft(num / 16, counter, letter_case) == -1)
			return (-1);
	}
	if (letter_case == HEX_LOW)
	{
		if (ft_putchar_ft("0123456789abcdef"[num % 16], counter) == -1)
			return (-1);
	}
	else if (letter_case == HEX_UPP)
	{
		if (ft_putchar_ft("0123456789ABCDEF"[num % 16], counter) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
