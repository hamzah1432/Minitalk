/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:34:24 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/12 17:31:47 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../libft/libft.h"

// char x = 5;

void handle_signal(int signum)
{
    if (signum == SIGUSR1) // If SIGUSR1 is received, print 0
        write(1, "0", 1);
    else if (signum == SIGUSR2) // If SIGUSR2 is received, print 1
        write(1, "1", 1);
}

int main(int argc, char **argv)
{
    int i = -1;
    int j = 8;
    unsigned char bit = 0;
    if (argc != 3)
    {
        write(1, "Error: arguments\n", 17);
        return (1);
    }
    int server_pid = ft_atoi(argv[1]);
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (argv[2][++i])
    {
        j = 8;
        while (--j >= 0)
        {
            bit = (unsigned char)argv[2][i];
            sleep(1);
            if ((bit >> j & 1) == 0)
                kill(server_pid, SIGUSR1);
            else if ((bit >> j & 1) == 1)
                kill(server_pid, SIGUSR2);
        }
    }

    return (0);
}
