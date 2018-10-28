/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:10:30 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 15:10:31 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define BACKGROUND 0
#define ABS(x) (x > 0 ? x : -x)

void	closest_inter(double *from_p, t_inter *inter, t_scene *scene)
{
	t_list			*objects;
	double			inter_points[2];

	objects = scene->objects;
	while (objects)
	{
		inter_ray_object(inter, inter_points, from_p, objects->content);
		change_params(inter_points[0], objects->content, inter);
		change_params(inter_points[1], objects->content, inter);
		objects = objects->next;
	}
}

void	set_light_st(t_light_st *light_st, double *start_point, \
	double *point, t_inter *inter)
{
	t_object *object;

	object = inter->closest_object;
	light_st->color = object->color;
	light_st->refl_intens = 0.0;
	light_st->color_intens = 0.0;
	light_st->point_on_object = add_sc(start_point, point, inter->closest_t);
	light_st->object_normal = \
		object->compute_normal(object, light_st->point_on_object);
	light_st->from_point_to_cam = mult_on_sc(inter->ray_dir, -1);
	light_st->len_from_point_to_cam = len(light_st->from_point_to_cam);
	light_st->object_specular = inter->closest_object->specular;
}

void	del_lightstate(t_light_st *light_st)
{
	ft_memdel((void **)&(light_st->point_on_object));
	ft_memdel((void **)&(light_st->from_point_to_cam));
	ft_memdel((void **)&(light_st->object_normal));
}

int		trace_ray(double *dir, double *start_point, t_scene *scene, \
		double ray_start, double ray_end, int recursion_depth)
{
	t_inter			inter;
	t_light_st		light_st;
	int				obj_color;
	double			*mirror_ray;
	double			*temp_dir;
	int 			refl_color;

	refl_color = 0;
	inter.ray_dir = dir;
	inter.from = ray_start;
	inter.to = ray_end;
	inter.closest_t = inter.to;
	inter.closest_object = NULL;
	closest_inter(start_point, &inter, scene);
	if (!inter.closest_object)
		return (BACKGROUND);
	set_light_st(&light_st, start_point, dir, &inter);
	if (inter.closest_object->refl > 0.001 && recursion_depth)
	{
		temp_dir = mult_on_sc(dir, -1);
		mirror_ray = refl_ray(light_st.object_normal, temp_dir, dot(light_st.object_normal, temp_dir));
		refl_color = to_rgb(trace_ray(mirror_ray, light_st.point_on_object, scene, 0.001, ray_end, recursion_depth-1), inter.closest_object->refl);
		ft_memdel((void **)&mirror_ray);
		ft_memdel((void **)&temp_dir);
	}
	obj_color = to_rgb(compute_color(&light_st, scene), 1-inter.closest_object->refl);
	del_lightstate(&light_st);
	return (add_two_color(obj_color, refl_color));
}