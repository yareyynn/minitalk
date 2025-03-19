#include "../inc/minitalk.h"

char	*g_string;

void signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	static int i;
	static int bit;

ft_printf("i = %d\n", i);

if (signum == SIGUSR2)
{
    ft_printf("Message is received\n");
    exit(0);
}

if (signum == SIGUSR1)
{
    if ((g_string[i] >> (7 - bit)) & 1)
        kill(info->si_pid, SIGUSR2);
    else
        kill(info->si_pid, SIGUSR1);
    bit++;

    if (bit == 8)
    {
        bit = 0;
        i++;
    }
}

}

int	main(int argc, char **argv)
{
	struct sigaction	c_sa;

	if (argc != 3)
	{
		ft_printf("Usage is: build/client <<Server_PID>> <<Mesaj>>\n");
		return (1);
	}

	g_string = argv[2];
	c_sa.sa_flags = SA_SIGINFO;
	c_sa.sa_sigaction = signal_handler;

	kill(ft_atoi(argv[1]), SIGUSR1);
	sigaction(SIGUSR2, &c_sa, NULL);
	sigaction(SIGUSR1, &c_sa, NULL);

	while (1)
		pause();

	return (0);
}
