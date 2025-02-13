/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:34:24 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/13 18:23:53 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../libft/libft.h"

static  char received = 0;

void handle_ack(int sig)
{
    (void)sig;
    received = 1;
    printf("\n 1 bit\n");
}

void send_char(pid_t server_pid, char c)
{
    int bit;
    
    for (bit = 7; bit >= 0; bit--)
    {
        received = 0;
        if ((c >> bit) & 1)
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
        
        while (!received)
            pause();
    }
}

void send_string(pid_t server_pid, char *str)
{
    while (*str)
    {
        send_char(server_pid, *str);
        str++;
    }
    send_char(server_pid, '\0');
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    pid_t server_pid;

    if (argc != 3)
    {
        ft_putstr_fd("Usage: ./client [server_pid] [message]\n", 2);
        return (1);
    }

    sa.sa_handler = handle_ack;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_putstr_fd("Failed to set up signal handler\n", 2);
        return (1);
    }

    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0)
    {
        ft_putstr_fd("Invalid server PID\n", 2);
        return (1);
    }

    send_string(server_pid, argv[2]);
    return (0);
}
