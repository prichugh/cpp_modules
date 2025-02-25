/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:20:56 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/15 12:20:56 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>

int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
void	send_message_signal(int pid, char *message);
void	send_byte(int pid, unsigned char byte);
void	send_bit(int pid, int bit);
void	acknowledgment_handler(int signum);
void	ft_putnbr(int n);
int		ft_putstr(char *s);

#endif
