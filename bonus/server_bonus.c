/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:05:21 by schahir           #+#    #+#             */
/*   Updated: 2025/03/18 03:18:27 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void ft_handle_signal(int signal, siginfo_t *info, void *context)
{
    static char c;
    static int  bit;
    static pid_t    c_id;
    (void)context;

    if (c_id != info->si_pid)
    {
        c_id = info->si_pid;
        bit = 0;
        c = 0;
    }
    if (signal == SIGUSR2)
        c = c * 2 + 1;
    else if (signal == SIGUSR1)
        c = c * 2;
    bit++;
   	if (bit == 8)
	{
		if (c == '\0')
        {
			write(1, "\n", 1);
            kill(c_id, SIGUSR2);
        }
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
    kill(c_id, SIGUSR1);
}

int main (int ac, char **av)
{
    pid_t pid;
    struct sigaction sa;

    (void)av;
    if(ac !=1)
        return(ft_putstr_fd("Error: too many arguments\n", 2), 1);
    pid = getpid();
    ft_printf("%d\n", pid);
    sa.sa_sigaction = ft_handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
}