/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:48:52 by schahir           #+#    #+#             */
/*   Updated: 2025/03/02 17:22:06 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_abs - Computes the absolute value of an integer.
 *
 * @n: The integer to compute the absolute value of.
 *
 * Return: The absolute value of the integer.
 */
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
