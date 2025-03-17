#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

void signal_handler(int signum);
void send_char(pid_t server_pid, char c);

#endif
