/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:29:13 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:29:14 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	*compute_tangent(double *point_on_object, double *c, \
	double sc, double *dir)
{
	double	*long_dir;
	double	*new_c;
	double	*tangent;
	double	*radius;

	long_dir = mult_on_sc(dir, sc);
	new_c = add(c, long_dir);
	radius = sub(point_on_object, new_c);
	tangent = cross(radius, dir);
	ft_memdel((void **)&long_dir);
	ft_memdel((void **)&new_c);
	ft_memdel((void **)&radius);
	return (tangent);
}

double	*cone_normal(t_object *object, double *point_on_object)
{
	double	*creature;
	double	*tangent;
	double	*normal;
	double	sc;
	int		one;

	creature = sub(point_on_object, object->c);
	sc = dot(creature, object->dir);
	one = sc < 0 ? -1 : 1;
	tangent = compute_tangent(point_on_object, object->c, sc, object->dir);
	normal = cross(creature, tangent);
	ft_memdel((void **)&creature);
	creature = normal;
	normal = mult_on_sc(normal, one / len(normal));
	ft_memdel((void **)&creature);
	ft_memdel((void **)&tangent);
	return (normal);
}
