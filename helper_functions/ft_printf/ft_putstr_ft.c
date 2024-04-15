/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:09:40 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/20 12:47:25 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_null_str(size_t *counter)
{
	char	*null_str;
	size_t	str_len;

	null_str = "(null)";
	str_len = 6;
	if (write(1, null_str, str_len) == -1)
		return (-1);
	*counter += str_len;
	return (0);
}

int	ft_putstr_ft(char *str, size_t *counter)
{
	size_t	str_len;

	str_len = 0;
	if (!str)
	{
		return (handle_null_str(counter));
	}
	while (str[str_len] != '\0')
	{
		if (write(1, &str[str_len], 1) == -1)
			return (-1);
		str_len++;
	}
	*counter += str_len;
	return (0);
}
