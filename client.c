/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:30:53 by yabukirento       #+#    #+#             */
/*   Updated: 2024/08/02 17:32:36 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char *message, int i)
{
	while (*message)
	{
		i = 0;
		while (i < 8)
		{
			if (*message & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i++;
		}
		message++;
	}
	i = 0;
	while (i < 8)
	{
		if ('\0' & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	ft_signal_handler_client(int sig)
{
	if (sig == SIGUSR2)
	{
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3 || !ft_isdigit(*argv[1]))
	{
		write(1, "Usage: ./client [server_pid] [message]\n", 39);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
	{
		write(1, "Error: Invalid PID.\n", 20);
		return (1);
	}
	signal(SIGUSR2, ft_signal_handler_client);
	message = argv[2];
	ft_send_signal(pid, message, 0);
	return (0);
}
