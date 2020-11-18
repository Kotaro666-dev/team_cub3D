/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hexadecimal_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:28:22 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/18 17:02:59 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_game.h"
#include "libft.h"
#include "utilities.h"

static char	*convert_dec_to_hex(int color)
{
	char	hexaDeciNum[3];
	char	*hexCode;
	int		i;
	int		temp;

	if (!(hexCode = ft_calloc(3, sizeof(char))))
		return (NULL);
	i = 0;
	temp = 0;
	if (color == 0)
		ft_strlcpy(hexCode, "00", 3);
	while (color != 0)
	{
		temp = color % 16;
		if (temp < 10)
			hexaDeciNum[i] = temp + 48;
		else
			hexaDeciNum[i] = temp + 55;
		i++;
		color /= 16;
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
	hexCode[2] = '\0';
	return (hexCode);
}

static void	append_prefix_hex(char *hex)
{
	hex[0] = '0';
	hex[1] = 'x';
}

static char			*create_hexadecimal_color(int red, int green, int blue)
{
	char *hexCode;
	char *temp;

	if (!(hexCode = ft_calloc(9, sizeof(char))))
		return (NULL);
	append_prefix_hex(hexCode);
	if (!(temp = convert_dec_to_hex(red)))
		return (NULL);
	ft_strlcat(hexCode, temp, 9);
	free(temp);
	if (!(temp = convert_dec_to_hex(green)))
		return (NULL);
	ft_strlcat(hexCode, temp, 9);
	free(temp);
	if (!(temp = convert_dec_to_hex(blue)))
		return (NULL);
	ft_strlcat(hexCode, temp, 9);
	free(temp);
	temp = NULL;
	hexCode[8] = '\0';
	return (hexCode);
}

static int			set_hexadecimal_color(int red, int green, int blue, char *hex)
{
	char *temp;

	if (!(temp = create_hexadecimal_color(red, green, blue)))
	{
		return (ERROR);
	}
	ft_strlcpy(hex, temp, 9);
	free(temp);
	temp = NULL;
	return (TRUE);
}

int				convert_rgb_to_hex(t_cub_data *cub_data)
{
	int		red;
	int		green;
	int		blue;

	// FLOOR
	red = cub_data->clr_floor.red;
	green = cub_data->clr_floor.green;
	blue = cub_data->clr_floor.blue;
	if (set_hexadecimal_color(red, green, blue, cub_data->clr_floor.hex) == ERROR)
		return (ERROR);
	// CEILING
	red = cub_data->clr_ceiling.red;
	green = cub_data->clr_ceiling.green;
	blue = cub_data->clr_ceiling.blue;
	if (set_hexadecimal_color(red, green, blue, cub_data->clr_ceiling.hex) == ERROR)
		return (ERROR);
	return (TRUE);
}
