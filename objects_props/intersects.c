/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:37:27 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:37:28 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	inter_cylinder(double *cof, t_inter *inter, \
	double *to_center, t_object *object)
{
	double	*pre_a;
	double	*to_free;
	double	*pre_c;

	pre_a = mult_on_sc(object->dir, dot(inter->ray_dir, object->dir));
	to_free = pre_a;
	pre_a = sub(inter->ray_dir, pre_a);
	ft_memdel((void **)&to_free);
	pre_c = mult_on_sc(object->dir, dot(to_center, object->dir));
	to_free = pre_c;
	pre_c = sub(to_center, pre_c);
	ft_memdel((void **)&to_free);
	cof[0] = dot(pre_a, pre_a);
	cof[1] = 2 * dot(pre_a, pre_c);
	cof[2] = dot(pre_c, pre_c) - object->r * object->r;
	ft_memdel((void **)&pre_c);
	ft_memdel((void **)&pre_a);
}

void	inter_cone(double *cof, t_inter *inter, \
	double *to_center, t_object *object)
{
	double	to_center_dot_dir;
	double	ray_dir_dot_conic_dir;
	double	*pre_a;
	double	*pre_c;
	double	*to_free;

	to_center_dot_dir = dot(to_center, object->dir);
	ray_dir_dot_conic_dir = dot(inter->ray_dir, object->dir);
	pre_a = mult_on_sc(object->dir, ray_dir_dot_conic_dir);
	to_free = pre_a;
	pre_a = sub(inter->ray_dir, pre_a);
	ft_memdel((void **)&to_free);
	pre_c = mult_on_sc(object->dir, to_center_dot_dir);
	to_free = pre_c;
	pre_c = sub(to_center, pre_c);
	ft_memdel((void **)&to_free);
	cof[0] = dot(pre_a, pre_a) * object->sq_cos;
	cof[0] -= ray_dir_dot_conic_dir * ray_dir_dot_conic_dir * object->sq_sin;
	cof[1] = 2 * (dot(pre_a, pre_c) * object->sq_cos \
		- to_center_dot_dir * ray_dir_dot_conic_dir * object->sq_sin);
	cof[2] = dot(pre_c, pre_c) * object->sq_cos;
	cof[2] -= to_center_dot_dir * to_center_dot_dir * object->sq_sin;
	ft_memdel((void **)&pre_a);
	ft_memdel((void **)&pre_c);
}

void	inter_sphere(double *cof, t_inter *inter, \
	double *to_center, t_object *object)
{
	cof[0] = dot(inter->ray_dir, inter->ray_dir);
	cof[1] = 2 * dot(to_center, inter->ray_dir);
	cof[2] = dot(to_center, to_center) - object->r * object->r;
}

void	inter_plane(double *cof, t_inter *inter, \
	double *to_center, t_object *object)
{
	cof[0] = 0;
	cof[1] = dot(inter->ray_dir, object->dir);
	cof[2] = dot(to_center, object->dir);
}

void	inter_ray_object(t_inter *inter, double *inter_points, \
	double *from_point, t_object *object)
{
	double	cof[3];
	double	*to_center;

	to_center = sub(from_point, object->c);
	object->inter_cof(cof, inter, to_center, object);
	solve_eq(inter_points, cof);
	ft_memdel((void **)&to_center);
}
