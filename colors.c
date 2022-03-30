/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:59:33 by faventur          #+#    #+#             */
/*   Updated: 2022/03/30 22:31:53 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	rgb_to_hex_converter(t_color rgb)
{
	return (rgb.a << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_color	lerp(t_color a, t_color b, float t)
{
	a.r += (b.r - a.r) * t;
	a.g += (b.g - a.g) * t;
	a.b += (b.b - a.b) * t;
	a.a += (b.a - a.a) * t;
	return (a);
}

t_color	hex_to_rgb_converter(int hex_value)
{	
	t_color	rgb;

	rgb.a = ((hex_value >> 24) & 0xff);
	rgb.r = ((hex_value >> 16) & 0xff);
	rgb.g = ((hex_value >> 8) & 0xff);
	rgb.b = ((hex_value) & 0xff);
	printf("basic colors: %d, %d, %d, %d\n", rgb.r, rgb.g, rgb.b, rgb.a);
	return (rgb);
}

int	add_shade(double distance, int color)
{
	t_color	rgb;
	t_color	black;

	rgb = hex_to_rgb_converter(color);
	printf("%d, %d, %d, %d\n", rgb.r, rgb.g, rgb.b, rgb.a);
	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 255;
	if (distance >= 0 && distance <= 1)
	{
		rgb = lerp(rgb, black, distance);
		printf("%d, %d, %d, %d\n", rgb.r, rgb.g, rgb.b, rgb.a);
		color = rgb_to_hex_converter(rgb);
		printf("rgb: %d\n", color);
		return (color);
	}
	return (0x0);
}

int	get_opposite(int color)
{
	t_color	rgb;
	t_color	white;
	t_color	complem;

	rgb = hex_to_rgb_converter(color);
	white.r = 255;
	white.g = 255;
	white.b = 255;
	white.a = 255;
	complem.r = white.r - rgb.r;
	complem.g = white.g - rgb.g;
	complem.b = white.b - rgb.b;
	complem.a = white.a - rgb.a;
	printf("%d, %d, %d, %d\n", complem.r, complem.g, complem.b, complem.a);
	color = rgb_to_hex_converter(rgb);
	printf("rgb: %d\n", color);
	return (color);
}

int main()
{
	printf("%d\n", get_opposite(0xffff0000));
	printf("%d\n", get_opposite(0xff00ff00));
	printf("%d\n", get_opposite(0xff0000ff));
	printf("%d\n", get_opposite(0xffffffff));
}
