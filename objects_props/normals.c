/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:37:00 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:37:02 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	*cylinder_normal(t_object *object, double *point_on_object)
{
	double	*pre_normal;
	double	*new_c;
	double	*normal;
	double	*long_dir;
	double	sc;

	pre_normal = sub(point_on_object, object->c);
	sc = dot(pre_normal, object->dir);
	long_dir = mult_on_sc(object->dir, sc);
	new_c = add(object->c, long_dir);
	ft_memdel((void **)&pre_normal);
	ft_memdel((void **)&long_dir);
	pre_normal = sub(point_on_object, new_c);
	ft_memdel((void **)&new_c);
	normal = mult_on_sc(pre_normal, 1 / len(pre_normal));
	ft_memdel((void **)&pre_normal);
	return (normal);
}

double	*plane_normal(t_object *object, double *point_on_object)
{
	(void)point_on_object;
	return (mult_on_sc(object->dir, 1));
}

double	*sphere_normal(t_object *object, double *point_on_object)
{
	double	*pre_normal;
	double	*normal;

	pre_normal = sub(point_on_object, object->c);
	normal = mult_on_sc(pre_normal, 1.0 / len(pre_normal));
	ft_memdel((void **)&pre_normal);
	return (normal);
}
