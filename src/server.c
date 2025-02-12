#include "../include/minitalk.h"
#include "../libft/libft.h"

void handle_signal(int signum)
{
    if (signum == SIGUSR1) // If SIGUSR1 is received, print 0
        write(1, "0", 1);
    else if (signum == SIGUSR2) // If SIGUSR2 is received, print 1
        write(1, "1", 1);
}

int main(void)
{
    printf("Server PID: %d\n", getpid()); // Print server PID
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (1)
        pause();

    return 0;
}
