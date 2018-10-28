/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:43:06 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:43:07 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define GET_RED(x) (x >> 16)
#define GET_GREEN(x) ((x >> 8) & 0xff)
#define GET_BLUE(x) (x & 0xff)
#define DO_RGB(r, g, b) ((clip(r) << 16) | (clip(g) << 8) | clip(b))

int			clip(int color)
{
	if (color > 0xff)
		return (0xff);
	if (color < 0)
		return (0);
	return (color);
}

int			add_two_color(int color1, int color2)
{
	int c1[3];
	int c2[3];

	c1[0] = GET_RED(color1);
	c1[1] = GET_GREEN(color1);
	c1[2] = GET_BLUE(color1);
	c2[0] = GET_RED(color2);
	c2[1] = GET_GREEN(color2);
	c2[2] = GET_BLUE(color2);
	return (DO_RGB(c1[0] + c2[0], c1[1] + c2[1], c1[2] + c2[2]));
}

double		good_light_intensity(t_light_st *light_st)
{
	double intens;

	intens = 1 - light_st->refl_intens;
	if (intens <= 0)
		return (0.01 * light_st->color_intens);
	return (intens * light_st->color_intens);
}

int			to_rgb(int color, double lighting)
{
	int r;
	int g;
	int b;

	r = lighting * GET_RED(color);
	g = lighting * GET_GREEN(color);
	b = lighting * GET_BLUE(color);
	return (DO_RGB(r, g, b));
}

int			compute_color(t_light_st *light_st, t_scene *scene)
{
	int refl_color;
	int color;

	compute_light(light_st, scene);
	color = to_rgb(light_st->color, good_light_intensity(light_st));
	refl_color = to_rgb(0xffffff, light_st->refl_intens);
	return (add_two_color(refl_color, color));
}
