/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:20:51 by nmaturan          #+#    #+#             */
/*   Updated: 2023/06/17 23:00:38 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_lc {
  int len;
  int check;
} t_lc;

int ft_printf(const char *str, ...);
int format_handler(t_lc *total, va_list args, const char format);
int ft_strchr(t_lc *total, const char *str, char c);

void ft_putchar(t_lc *total, int c);
void ft_putstr(t_lc *total, char *s);

void ft_putptr(t_lc *total, unsigned long p);
void ft_putint(t_lc *total, int i);
void ft_putuint(t_lc *total, unsigned int u);
void ft_put_l_hex(t_lc *total, unsigned int x);
void ft_put_u_hex(t_lc *total, unsigned int X);

#endif
