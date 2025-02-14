/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:51:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/14 20:16:18 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_message	g_msg;

static void	print_char(void)
{
	if (g_msg.c == '\0')
		printf("\nMessage received!\n");
	else
		printf("%c", g_msg.c);
	g_msg.c = 0;
	g_msg.bits = 0;
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
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

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		printf("Error: Failed to setup signal handlers\n");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	g_msg.c = 0;
	g_msg.bits = 0;
	setup_signals();
	printf("Server PID: %d\n", getpid());
	printf("Waiting for messages...\n");
	while (1)
		pause();
	return (0);
}
