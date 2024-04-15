/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:49:37 by ogoman            #+#    #+#             */
/*   Updated: 2023/11/21 08:00:28 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOW 0
# define HEX_UPP 1
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		ft_putchar_ft(char c, size_t *counter);
int		ft_putstr_ft(char *str, size_t *counter);
int		ft_putptr_ft(void *ptr, size_t *counter);
int		ft_putnbr_ft(int num, size_t *counter);
int		ft_putuni_ft(unsigned int num, size_t *counter);
int		ft_puthex_ft(unsigned int num, size_t *counter, int letter_case);
int		ft_format(va_list ap, char *str, size_t *counter);

#endif
