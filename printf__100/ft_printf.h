/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:08:03 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/26 11:08:03 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		check_type(const char *format, int i, va_list args);
void	ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putstr_ptr(char *s);
char	*ft_itoa(int n);
char	*ft_puthex(unsigned int n, const char format);
char	*ft_putptr(void *ptr);

#endif
