/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:20:58 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/15 12:20:58 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*append_byte(char *message, int byte)
{
	int		i;
	int		len;
	char	*updated_message;

	i = 0;
	len = 0;
	while (message[len])
		len++;
	updated_message = malloc(sizeof(char) * (len + 2));
	if (!updated_message)
		return (NULL);
	while (message[i])
	{
		updated_message[i] = message[i];
		i++;
	}
	updated_message[i] = byte;
	updated_message[i + 1] = '\0';
	free (message);
	return (updated_message);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit_counter = 0;
	static int	byte = 0;
	static char	*message = NULL;

	(void)context;
	if (!message)
		message = ft_strdup("");
	if (signum == SIGUSR1)
		byte = (byte << 1);
	else if (signum == SIGUSR2)
		byte = (byte << 1) | 1;
	bit_counter++;
	if (bit_counter == 8)
	{
		message = append_byte(message, byte);
		if (byte == '\0')
		{
			ft_putstr(message);
			free (message);
			message = NULL;
		}
		bit_counter = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("No args needed\n");
		return (0);
	}
	ft_putstr("Process Identification: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = 0;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
