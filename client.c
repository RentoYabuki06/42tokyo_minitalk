/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:30:53 by yabukirento       #+#    #+#             */
/*   Updated: 2024/08/14 22:24:58 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send_signal(int pid, char message)
{
	int				i;
	int				result;
	unsigned char	c;

	i = 8;
	c = message;
	while (i--)
	{
		if (c & 128)
			result = kill(pid, SIGUSR1);
		else if (!(c & 128))
			result = kill(pid, SIGUSR2);
		if (result == -1)
		{
			write(1, "Error: Invalid PID.\n", 20);
			return (1);
		}
		c = c << 1;
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		result;
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
	message = argv[2];
	i = -1;
	while (message[++i])
	{
		result = ft_send_signal(pid, message[i]);
		if (result == 1)
			return (0);
	}
	return (0);
}
