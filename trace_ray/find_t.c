/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:30:27 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 15:30:29 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	change_params(double t, t_object *object, t_inter *inter)
{
	if (t < inter->closest_t && t >= inter->from && t <= inter->to)
	{
		inter->closest_t = t;
		inter->closest_object = object;
	}
}

void	solve_eq(double *inter_points, double *cof)
{
	double disc;
	double sc_disc;

	inter_points[0] = DBL_MAX;
	inter_points[1] = DBL_MAX;
	if (ABS(cof[0]) < 0.0000001)
	{
		if (ABS(cof[1]) > 0.000001)
			inter_points[0] = -cof[2] / cof[1];
		return ;
	}
	disc = SQUARE(cof[1]) - 4 * cof[0] * cof[2];
	if (disc < 0)
		return ;
	sc_disc = sqrt(disc);
	inter_points[0] = (-cof[1] + sc_disc) / (2 * cof[0]);
	inter_points[1] = (-cof[1] - sc_disc) / (2 * cof[0]);
}
