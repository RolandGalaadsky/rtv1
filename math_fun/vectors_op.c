/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:15:21 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:15:23 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	*get_zero_vec(void)
{
	double *v;

	v = (double *)ft_memalloc(DOUB_ARR_SIZE);
	check_malloc(v);
	return (v);
}

double	*refl_ray(double *object_normal, double *light_vector, \
	double normal_dot_light_vector)
{
	double *light_on_normal;
	double *light_reflection;

	light_on_normal = mult_on_sc(object_normal, 2.0 * normal_dot_light_vector);
	light_reflection = sub(light_on_normal, light_vector);
	ft_memdel((void **)&light_on_normal);
	return (light_reflection);
}

double	*cross(double *u, double *v)
{
	double *res;

	res = get_zero_vec();
	res[0] = u[1] * v[2] - u[2] * v[1];
	res[1] = -u[0] * v[2] + u[2] * v[0];
	res[2] = u[0] * v[1] - u[1] * v[0];
	return (res);
}
