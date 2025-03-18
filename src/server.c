#include "../inc/minitalk.h"

void get_message(char c, int pid)
{
    static char *str = NULL;
    char *temp;

    if (!str)
    {
        str = (char *)malloc(1);
        if (!str)
            return;
        str[0] = '\0';
    }

    if (c == 0)
        {
            kill(pid, SIGUSR2);
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
}
void signal_handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bit = 0;

    (void)context;
    if (signum == SIGUSR2)
        c |= (1 << (7 - bit));
    bit++;

    if (bit == 8)
    {
        get_message(c, info->si_pid);
        c = 0;
        bit = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;
    int pid;

    pid = getpid();
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    ft_printf("Server PID: %d\n", pid);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();

    return (0);
}
