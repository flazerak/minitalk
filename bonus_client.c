/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:20:54 by flazerak          #+#    #+#             */
/*   Updated: 2022/06/18 15:23:57 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

void	msg_handler(int signum)
{
	if (signum == 30)
		write(1, "\nMessage received", 17);
}

void	send_signals(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_c(str[i], pid);
		i++;
	}
	send_c('\0', pid);
}

void	send_c(char c, int pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (c & (128 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep (800);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, msg_handler);
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		write(1, "invalid arguments \n", 19);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "invalid pid \n", 13);
		return (1);
	}
	send_signals(argv[2], pid);
	return (0);
}
