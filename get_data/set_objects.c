/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:03:56 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:04:03 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		set_sphere(char **info, t_object *object)
{
	object->inter_cof = inter_sphere;
	object->compute_normal = sphere_normal;
	object->r = ft_atod(info[5]);
}

void		set_plane(char **info, t_object *object)
{
	(void)info;
	object->inter_cof = inter_plane;
	object->compute_normal = plane_normal;
}

void		set_cylinder(char **info, t_object *object)
{
	object->inter_cof = inter_cylinder;
	object->compute_normal = cylinder_normal;
	object->r = ft_atod(info[6]);
}

void		set_cone(char **info, t_object *object)
{
	double angle;

	object->inter_cof = inter_cone;
	object->compute_normal = cone_normal;
	angle = ft_atod(info[6]) * DEGREE;
	object->sq_cos = cos(angle);
	object->sq_cos *= object->sq_cos;
	object->sq_sin = sin(angle);
	object->sq_sin *= object->sq_sin;
}
