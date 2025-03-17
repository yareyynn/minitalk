#include "../inc/minitalk.h"

void signal_handler(int signum)
{
    static char c = 0;
    static int bit = 0;
    static char *str = NULL;
    char *temp;

    if (!str)
    {
        str = (char *)malloc(1);
        if (!str)
            return;
        str[0] = '\0';
    }

    if (signum == SIGUSR2)
        c |= (1 << (7 - bit));
    bit++;


    if (bit == 8)
    {
        if (c == 10)
        {
            ft_printf("%s\n", str);
            free(str);
            str = NULL;
        }
        else
        {
            temp = str;
            str = ft_strjoin(str, &c);
            free(temp);
        }
        c = 0;
        bit = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("Server PID: %d\n", pid);

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1)
        pause();

    return (0);
}
