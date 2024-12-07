#include "minitalk.h"

void signal_handler(int sig)
{
    static char c  ;
    static int bit_count ;

    if (sig == SIGUSR1)
    c = c | 1;

    bit_count++;
    if (bit_count == 8)
    {
        write(1, &c, 1);
        if (c == '\0')
            write(1, "\n", 1);
        c = 0;
        bit_count = 0;
    }
    else
    {
        c <<= 1;
    }
}

int main(void)
{
    
    char *pid;
    int i;

    pid = ft_itoa(getpid());
    i = 0;
    write(1, "Server PID: ", 12);
    while(pid[i])
        write(1,&pid[i++],1);
   write(1, "\n", 1);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1)
        pause();
    return (0);
}
