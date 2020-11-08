/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:32:00 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 19:25:28 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_from_front(char const *str, char const *target)
{
	int i;
	int cnt;
	int flag;

	cnt = 0;
	while (*str != '\0')
	{
		i = 0;
		flag = 0;
		while (target[i] != '\0')
		{
			if (target[i++] == *str)
			{
				cnt++;
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			break ;
		str++;
	}
	return (cnt);
}

static int	count_from_back(char const *str, char const *target, const char *s1)
{
	int i;
	int cnt;
	int flag;

	cnt = 0;
	while (str != s1)
	{
		i = 0;
		flag = 0;
		while (target[i] != '\0')
		{
			if (target[i] == *str)
			{
				cnt++;
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
			break ;
		str--;
	}
	return (cnt);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		front_trim_len;
	int		behind_trim_len;
	int		final_length;
	int		i;

	front_trim_len = count_from_front(s1, set);
	behind_trim_len = count_from_back(s1 + ft_strlen(s1) - 1, set, s1);
	final_length = ft_strlen(s1) - front_trim_len - behind_trim_len;
	if (final_length < 0)
		final_length = 0;
	if (!(result = (char *)malloc(sizeof(char) * (final_length + 1))))
		return (NULL);
	i = 0;
	while (i < final_length)
	{
		result[i] = s1[front_trim_len + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
