/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:32:02 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 09:32:20 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	ans;

	i = 0;
	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((ans > (INT64_MAX / 10))
			|| (ans == (INT64_MAX / 10) && (str[i] >= '8' && str[i] <= '9')))
			break ;
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)ans);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
