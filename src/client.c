/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:34:24 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/14 20:13:38 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_received;

static void	handle_signal(int sig)
{
	if (sig)
		g_received = 1;
}

static int	send_byte(int pid, unsigned char byte)
{
	int	i;
	int	signal;

	i = 7;
	while (i >= 0)
	{
		g_received = 0;
		if ((byte >> i & 1) == 1)
			signal = SIGUSR2;
		else
			signal = SIGUSR1;
		if (kill(pid, signal) == -1)
			return (0);
		while (!g_received)
			usleep(50);
		i--;
	}
	return (1);
}

static int	send_str(int pid, char *str)
{
	while (*str && send_byte(pid, *str))
		str++;
	return (send_byte(pid, '\0'));
}

static int	check_pid(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i]))
		{
			ft_putendl_fd("\nPID must contain only digits", 2);
			return (0);
		}
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
	{
		ft_putendl_fd("\\nInvalid PID value", 2);
		return (0);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	struct sigaction		signal_info;
	int						pid;

	if (argc != 3)
	{
		ft_putendl_fd("Expected 2 argument", 2);
		return (1);
	}
	signal_info.sa_handler = handle_signal;
	signal_info.sa_flags = 0;
	sigemptyset(&signal_info.sa_mask);
	if (sigaction(SIGUSR1, &signal_info, NULL) == -1)
	{
		ft_putendl_fd("Signal handling failed", 2);
		return (1);
	}
	pid = check_pid(argv[1]);
	if (!send_str(pid, argv[2]) || !pid)
	{
		ft_putendl_fd("\nPID is not correct or faild to kill", 2);
		return (1);
	}
	return (0);
}
