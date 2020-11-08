/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 12:19:44 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/01 19:21:03 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL || (*f) == NULL)
	{
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
