/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:34:24 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/08 00:40:47 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
    int server_pid = atoi(argv[1]);

    while (argv[2][++i])
    {
        if (argv[2][i] == '0')
            kill(server_pid, SIGUSR1);
        else if (argv[2][i] == '1')
            kill(server_pid, SIGUSR2);
    }

    return (0);
}

void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit = 0;

    while (i--)
    {
        bit = (octet >> i & 1) + 48;
        write(1, &bit, 1);
    }
}