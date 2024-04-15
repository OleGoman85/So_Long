/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:03:43 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/17 16:03:27 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max_min(size_t *counter)
{
	char	*max_min;

	max_min = "-2147483648";
	while (*max_min != '\0')
	{
		if (ft_putchar_ft(*max_min, counter) == -1)
			return (-1);
		max_min++;
	}
	return (0);
}

int	ft_putnbr_ft(int num, size_t *counter)
{
	if (num == INT_MIN)
	{
		if (ft_max_min(counter) == -1)
			return (-1);
		return (0);
	}
	if (num < 0)
	{
		if (ft_putchar_ft('-', counter) == -1)
			return (-1);
		num = -num;
	}
	if (num / 10)
	{
		if (ft_putnbr_ft(num / 10, counter) == -1)
			return (-1);
	}
	if (ft_putchar_ft((num % 10) + '0', counter) == -1)
		return (-1);
	return (0);
}
