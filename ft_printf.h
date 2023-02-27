/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:11:31 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/20 17:45:15 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_putnbr_count(int n, int *count);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count);
void	ft_putnbr_hex_int(int nb, char *base, int *count);
void	ft_putnbr_hex_unsigned(unsigned long nb,
			char *base, int *count);
void	ft_putvoid_addrr(unsigned long nb, int *count);
void	ft_putnbr_hex(int nb, char *base, int *count);

void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *s, int *count);
int		ft_printf(const char *str, ...);

#endif
