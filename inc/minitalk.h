#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

void signal_handler(int signum, siginfo_t *info, void *context);
void send_message(int pid, char *str);
void get_message(char c, int pid);

#endif
