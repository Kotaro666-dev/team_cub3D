/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:47:30 by kkamashi          #+#    #+#             */
/*   Updated: 2020/10/20 16:17:18 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *result;
	size_t i;
	size_t length_from_start;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	length_from_start = ft_strlen(s + start);
	if (length_from_start < len)
	{
		len = length_from_start;
	}
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
