/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:51:39 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/12 17:23:55 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include "../include/minitalk.h"
#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t received_bit = 0;
volatile sig_atomic_t bit_count = 0;
volatile char current_char = 0;

void handle_signal(int sig, siginfo_t *info, void *context) {
    (void)context; // Unused
    if (sig == SIGUSR1) {
        current_char = (current_char << 1); // Append 0
    } else if (sig == SIGUSR2) {
        current_char = (current_char << 1) | 1; // Append 1
    }

    bit_count++;

    if (bit_count == 8) { // Full character received
        if (current_char == '\0') {
            printf("\nMessage received!\n");
        } else {
            printf("%c", current_char);
            fflush(stdout);
        }
        current_char = 0;
        bit_count = 0;
    }

    // Send ACK signal back to sender
    kill(info->si_pid, SIGUSR1);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Server PID: %d\n", getpid());
    printf("Waiting for messages...\n");

    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
