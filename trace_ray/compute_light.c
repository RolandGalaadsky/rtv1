/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:45:57 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:45:58 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define RAYSTART 0.001

double	compute_reflection(t_light_st *lightstate, double light_intens, \
	double normal_dot_light, double *light_v)
{
	double	*light_ref;
	double	ref_dot_point_to_cam;
	double	intens;
	double	len_f_p_t_c;
	double	*object_normal;

	object_normal = lightstate->object_normal;
	len_f_p_t_c = lightstate->len_from_point_to_cam;
	intens = 0;
	if (lightstate->object_specular <= -1)
		return (0);
	light_ref = refl_ray(object_normal, light_v, normal_dot_light);
	ref_dot_point_to_cam = dot(light_ref, lightstate->from_point_to_cam);
	if (ref_dot_point_to_cam > 0)
		intens += pow(ref_dot_point_to_cam / (len(light_ref) * len_f_p_t_c)\
			, lightstate->object_specular) * light_intens;
	ft_memdel((void **)&light_ref);
	return (intens);
}

int		is_shadow(double *point, int ray_end, double *light, t_scene *scene)
{
	t_inter			inter;
	int				is_shadow;

	if (!scene->shadow)
		return (0);
	inter.from = RAYSTART;
	inter.to = ray_end;
	inter.closest_t = DBL_MAX;
	inter.ray_dir = light;
	inter.closest_object = NULL;
	closest_inter(point, &inter, scene);
	is_shadow = (inter.closest_object != NULL);
	return (is_shadow);
}

void	diff_and_ref(t_light *light, t_light_st *lightstate, t_scene *scene)
{
	double		*light_v;
	double		normal_dot_light;
	double		ray_end;

	ray_end = 1;
	light_v = sub(light->info, lightstate->point_on_object);
	if (is_shadow(lightstate->point_on_object, ray_end, light_v, scene))
	{
		ft_memdel((void **)&light_v);
		return ;
	}
	normal_dot_light = dot(lightstate->object_normal, light_v);
	if (normal_dot_light > 0)
	{
		lightstate->color_intens += (light->intensity * normal_dot_light) \
			/ len(light_v);
		lightstate->refl_intens += compute_reflection(lightstate, \
			light->intensity, normal_dot_light, light_v);
	}
	ft_memdel((void **)&light_v);
}

void	compute_light(t_light_st *lightstate, t_scene *scene)
{
	t_list	*lightes;
	t_light	*light;

	lightes = scene->lightes;
	while (lightes)
	{
		light = (t_light *)lightes->content;
		if (light->type == POINT)
			diff_and_ref(light, lightstate, scene);
		else if (light->type == AMBIENT)
			lightstate->color_intens += light->intensity;
		lightes = lightes->next;
	}
}
