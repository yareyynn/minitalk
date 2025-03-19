#include "../inc/minitalk.h"

void get_message(char c, int pid)
{
    static char *str = NULL;
    char *temp;
    static char *ptr;

    if (!str)
    {
        str = (char *)malloc(1);
        if (!str)
            return;
        str[0] = '\0';
    }
    if (!ptr)
        {
        ptr = (char *)malloc(2);
        if (!ptr)
            return;
        ptr[0] = c;
        ptr[1] = '\0';
        }
    ptr[0] = c;
    if (c == 0)
        {
            ft_printf("%s\n", str);
            free(str);
            free(ptr);
            str = NULL;
            ptr = NULL;
            kill(pid, SIGUSR2);
        }
    else
        {
            temp = str;
            str = ft_strjoin(str, ptr);
            free(temp);
        }
}
void signal_handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bit = 0;
    static int flag = 0;

    (void)context;
    if(flag==1){
        if (signum == SIGUSR2)
            c |= (1 << (7 - bit));
        bit++;

    if (bit == 8)
        {
            get_message(c, info->si_pid);
            if(c == 0)
            {
                flag = 0;
                bit = 0;
                return;
            }
            c = 0;
            bit = 0;
        }
    }
    if(signum == SIGUSR1)
        flag = 1;
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
