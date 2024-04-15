/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuni_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:29:06 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/20 12:46:00 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuni_ft(unsigned int num, size_t *counter)
{
	if (num / 10)
	{
		if (ft_putuni_ft(num / 10, counter) == -1)
			return (-1);
	}
	if (ft_putchar_ft((num % 10) + '0', counter) == -1)
		return (-1);
	return (0);
}
