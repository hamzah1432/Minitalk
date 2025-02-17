/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:51:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/16 21:05:09 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_message	g_msg;

static void	print_char(void)
{
	if (g_msg.c == '\0')
	{
		ft_putstr_fd(g_msg.str, 1);
		ft_putstr_fd("\n", 1);
		free(g_msg.str);
		g_msg.str = 0;
	}
	else
	{
		if (g_msg.str == 0)
		{
			g_msg.str = malloc(2);
			g_msg.str[0] = g_msg.c;
			g_msg.str[1] = 0;
		}
		else
			ft_append(&g_msg.str, g_msg.c);
	}
	g_msg.c = 0;
	g_msg.bits = 0;
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			g_msg.c = (g_msg.c << 1);
		else if (sig == SIGUSR2)
			g_msg.c = (g_msg.c << 1) | 1;
		g_msg.bits++;
		if (g_msg.bits == 8)
			print_char();
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
}

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: Failed to setup signal handlers\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	g_msg.c = 0;
	g_msg.bits = 0;
	setup_signals();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
