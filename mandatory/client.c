/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:59:56 by schahir           #+#    #+#             */
/*   Updated: 2025/03/17 17:05:13 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bits(char c, pid_t pid)
{
	int *arr = ft_calloc(sizeof(int) * 8, 0);
	if (!arr)
		return ;
	int i = 7;

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
		i++;
		usleep(10000);
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
	//ft_printf("%d\n", pid);
	message = av[2];
	while(*message)
		send_bits(*message++, pid);
	return 0;
}

