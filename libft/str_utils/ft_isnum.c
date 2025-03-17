/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:57:11 by schahir           #+#    #+#             */
/*   Updated: 2025/03/16 00:57:24 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_valid_number(char *str)
{
	long	value;

	int (i), (sign);
	i = 0, value = 0, sign = 1;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
		if ((sign == 1 && value > INT_MAX) || (sign == -1
				&& value > (long)INT_MAX + 1))
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
