/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:59:56 by schahir           #+#    #+#             */
/*   Updated: 2025/03/18 16:52:19 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static int g_sent;

void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_putstr_fd("Error: Kill Failed!\n", 2);
		exit(1);
	}
}

void	ft_done(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message Sent Successfully!\n");	
}

void	ft_resend(int signal)
{
	if (signal == SIGUSR1)
		g_sent = 1;
}

void	send_bits(unsigned char c, pid_t pid)
{
	int	i;
	int	*arr;

	if (!(arr = malloc(sizeof(int) * 8)))
		return ;
	i = 7;
	while(i >= 0)
	{
		arr[i] = c % 2;
		c /= 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if(arr[i])
			send_signal(pid, SIGUSR2);
		else
			send_signal(pid, SIGUSR1);
		while (!g_sent)
			;
		g_sent = 0;
		i++;
	}
	free(arr);
}

int main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	
    if(ac != 3)
		return(ft_putstr_fd("Error: Too many arguments\n", 2), 1);
	if(!is_valid_number(av[1]))
		return(ft_putstr_fd("Error: Invalid PID\n", 2), 1);
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_resend);
	signal(SIGUSR2, ft_done);
	message = av[2];
	while(*message)
		send_bits(*message++, pid);
	send_bits('\0', pid);
	return 0;
}

