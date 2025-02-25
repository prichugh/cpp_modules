/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:20:54 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/15 12:20:54 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_acknowledged = 0;

void	acknowledgment_handler(int signum)
{
	static int	i = 0;

	(void)signum;
	g_acknowledged = 1;
	if (i == 0)
	{
		ft_putstr("confirmation received!\n");
		i = 1;
	}
}

void	send_bit(int pid, int bit)
{
	g_acknowledged = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (!g_acknowledged)
		;
}

void	send_byte(int pid, unsigned char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, (byte >> i) & 1);
		i--;
	}
}

void	send_message_signal(int pid, char *message)
{
	int	byte;
	int	i;

	byte = 0;
	while (message[byte])
	{
		send_byte(pid, (unsigned char)message[byte]);
		byte++;
	}
	i = 0;
	while (i < 8)
	{
		send_bit(pid, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc != 3)
	{
		ft_putstr("Too many or too few arguments.\n");
		ft_putstr("Send a message as follows: ./client PID \"MESSAGE\"\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (!pid || kill(pid, 0) == -1)
	{
		ft_putstr("Bad PID\n");
		return (0);
	}
	message = argv[2];
	if (message[0] == 0)
	{
		ft_putstr("No message to send\n");
		return (0);
	}
	signal(SIGUSR1, acknowledgment_handler);
	send_message_signal(pid, message);
	return (0);
}
