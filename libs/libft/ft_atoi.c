/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:42:20 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/26 15:23:41 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

static int		is_result_overflow(long long int num)
{
	if (num > INT_MAX)
	{
		return (1);
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	long long int	result;
	int				is_minus;

	if (str == NULL)
		return (0);
	result = 0;
	is_minus = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_minus = *str == '-' ? -1 : 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (is_result_overflow(result))
	{
		return (-1);
	}
	return ((int)(result * is_minus));
}
