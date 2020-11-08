/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:30:25 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 14:20:00 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc_digits(int n)
{
	int		i;

	if (n == 0)
	{
		i = 1;
		return (i);
	}
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		ft_reverse(char *str, size_t length)
{
	size_t	start;
	size_t	end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static char		*input_string(int num, char *str, int digits, int is_minus)
{
	int		i;
	int		temp;

	i = 0;
	while (digits > 0)
	{
		temp = num % 10;
		if (temp < 0)
		{
			temp *= -1;
		}
		str[i] = temp + '0';
		num /= 10;
		digits--;
		i++;
	}
	if (is_minus == 1)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		is_minus;

	digits = calc_digits(n);
	is_minus = 0;
	if (n == INT_MIN)
	{
		return (ft_strdup("-2147483648"));
	}
	if (n < 0)
	{
		is_minus = 1;
		n *= -1;
	}
	str = (char *)malloc(sizeof(char) * (digits + is_minus + 1));
	if (!str)
		return (NULL);
	input_string(n, str, digits, is_minus);
	ft_reverse(str, ft_strlen(str));
	return (str);
}
