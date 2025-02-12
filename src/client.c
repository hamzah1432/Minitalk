/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:34:24 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/12 05:40:57 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../libft/libft.h"

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

    while (argv[2][++i])
    {
        if (argv[2][i] == '0')
            kill(server_pid, SIGUSR1);
        else if (argv[2][i] == '1')
            kill(server_pid, SIGUSR2);
    }

    return (0);
}