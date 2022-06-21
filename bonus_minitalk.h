/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:26:28 by flazerak          #+#    #+#             */
/*   Updated: 2022/06/19 20:56:23 by flazerak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int	g_pid;
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	handlersig(int signum, siginfo_t *siginfo, void *context);
void	send_signals(char *str, int pid);
void	send_c(char c, int pid);
void	msg_handler(int signum);
void	reset(char c, int shift, int pid);

#endif
