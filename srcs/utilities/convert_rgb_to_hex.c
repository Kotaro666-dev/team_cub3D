/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_to_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:28:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/18 14:33:25 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "libft.h"
#include "utilities.h"

static char	*decToHexa(int color)
{
	char	hexaDeciNum[3];
	char	*hexCode;
	int		i;
	int		temp;

	if (!(hexCode = (char *)malloc(sizeof(char) * (2 + 1))))
		return (NULL);
	i = 0;
	temp = 0;
	while (color != 0)
	{
		temp = color % 16;
		if (temp < 10)
			hexaDeciNum[i] = temp + 48;
		else
			hexaDeciNum[i] = temp + 55;
		i++;
		color = color / 16;
	}
	hexaDeciNum[2] = '\0';
	if (i == 2)
	{
		hexCode[0] = hexaDeciNum[1];
		hexCode[1] = hexaDeciNum[0];
	}
	else if (i == 1)
	{
		hexCode[0] = '0';
		hexCode[1] = hexaDeciNum[0];
	}
	else if (i == 0)
		ft_strlcpy(hexCode, "00", 2);
	return (hexCode);
}

static void	append_prefix_0x(char *hex)
{
	hex[0] = '0';
	hex[1] = 'x';
}

static char			*convert_rgb_to_hex(int red, int green, int blue)
{
	char *hexCode;
	char *temp;

	if (!(hexCode = (char *)malloc(sizeof(char) * (8 + 1))))
		return (NULL);
	append_prefix_0x(hexCode);
	temp = decToHexa(red);
	ft_strlcat(hexCode, temp, 9);
	free(temp);
	temp = decToHexa(green);
	ft_strlcat(hexCode, temp, 9);
	free(temp);
	temp = decToHexa(blue);
	ft_strlcat(hexCode, temp, 9);
	free(temp);
	temp = NULL;
	hexCode[8] = '\0';
	// どうやらここのhexcodeで使用しているメモリを開放していないことが原因？
	return (hexCode);
}

void		set_hexadecimal_color(t_cub_data *cub_data)
{
	char	*temp;
	int		red;
	int		green;
	int		blue;

	// FLOOR
	red = cub_data->clr_floor.red;
	green = cub_data->clr_floor.green;
	blue = cub_data->clr_floor.blue;
	temp = convert_rgb_to_hex(red, green, blue);
	ft_strlcpy(cub_data->clr_floor.hex, temp, 9);
	free(temp);
	// CEILING
	red = cub_data->clr_ceiling.red;
	green = cub_data->clr_ceiling.green;
	blue = cub_data->clr_ceiling.blue;
	temp = convert_rgb_to_hex(red, green, blue);
	ft_strlcpy(cub_data->clr_ceiling.hex, temp, 9);
	free(temp);
	temp = NULL;
}
