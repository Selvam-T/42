/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:00:59 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 14:23:14 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s, int reverse);
size_t	ft_putint(int n);
size_t	ft_putnbr(unsigned int n, size_t count);
size_t	ft_hexadecimal(unsigned long long decimal, int c);
size_t	ft_ptraddress(void *decimal);
int		ft_printf(const char *args, ...);
#endif
