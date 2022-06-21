/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:03:35 by flazerak          #+#    #+#             */
/*   Updated: 2022/06/19 20:55:26 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

void	reset(char c, int shift, int pid)
{
	c = 0;
	shift = 0;
	g_pid = pid;
}

void	handlersig(int signum, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	shift;

	(void) context;
	if (g_pid != siginfo->si_pid)
		reset(c, shift, siginfo->si_pid);
	if (signum == SIGUSR2)
	{
		c <<= 1;
		c |= 1;
	}
	if (signum == SIGUSR1)
		c <<= 1;
	if (++shift == 8)
	{
		shift = 0;
		if (c == '\0')
			kill(g_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	write(1, "server PID: ", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sig.sa_sigaction = handlersig;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
