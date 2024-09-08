/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:31:05 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 09:32:53 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	static int				bit_count = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	if (signal(SIGUSR1, ft_handler) == SIG_ERR)
	{
		ft_printf("Error: Failed to set signal handler for SIGUSR1.\n");
		return (1);
	}
	if (signal(SIGUSR2, ft_handler) == SIG_ERR)
	{
		ft_printf("Error: Failed to set signal handler for SIGUSR2.\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
