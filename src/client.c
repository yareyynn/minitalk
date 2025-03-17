#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1) 
			kill(server_pid, SIGUSR2);
		else 
			kill(server_pid, SIGUSR1);
		usleep(145);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;
    printf("ananı skm");
	if (argc != 3)
	{
		write(2, "Kullanım: ./client <Server_PID> <Mesaj>\n", 40);
		return (1);
	}
	server_pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		send_char(server_pid, argv[2][i++]);
	send_char(server_pid, '\n');
	return (0);
}
