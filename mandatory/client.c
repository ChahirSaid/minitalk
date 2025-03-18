/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:59:56 by schahir           #+#    #+#             */
/*   Updated: 2025/03/18 02:03:25 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int g_sent;

void ft_resend(int signal)
{
	if (signal == SIGUSR1)
		g_sent = 1;
}

void	send_bits(char c, pid_t pid)
{
	int i;
	
	int *arr = malloc(sizeof(int) * 8);
	if (!arr)
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
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_sent)
			;
		i++;
		g_sent = 0;
	}
	free(arr);
}

int main(int ac, char **av)
{
	char *message;
	
    if(ac != 3)
		return(ft_putstr_fd("Error: Too many arguments\n", 2), 1);
	if(!is_valid_number(av[1]))
		return(ft_putstr_fd("Error: Invalid PID\n", 2), 1);
	pid_t pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_resend);
	message = av[2];
	while(*message)
		send_bits(*message++, pid);
	if (*message == '\0')
		send_bits(*message, pid);
	return 0;
}

