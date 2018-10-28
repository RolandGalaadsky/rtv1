/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:00:22 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:00:23 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define NOSPECULAR -1
#define SPHERE "SPHERE"
#define CYLINDER "CYLINDER"
#define CONE "CONE"
#define PLANE "PLANE"

void		get_direction(char *info, t_object *object)
{
	double	**rotate_matrix;
	double	**trans;

	object->dir = get_zero_vec();
	object->dir[1] = 1;
	rotate_matrix = get_rotate_matrix(info);
	trans = trans_matrix(rotate_matrix);
	rotate(object->dir, trans);
	del_matrix(&rotate_matrix);
	del_matrix(&trans);
}

void		new_object(char **info, t_object *object, int inf_len)
{
	int		*color;
	int		d;

	d = 0;
	if (!ft_strcmp(info[0], SPHERE) && inf_len == 7)
		set_sphere(info, object);
	else if ((d = (!ft_strcmp(info[0], CYLINDER) && inf_len == 8)))
		set_cylinder(info, object);
	else if ((d = (!ft_strcmp(info[0], CONE) && inf_len == 8)))
		set_cone(info, object);
	else if ((d = (!ft_strcmp(info[0], PLANE) && inf_len == 7)))
		set_plane(info, object);
	else
		error_file();
	color = get_int_arr(info[1]);
	object->specular = ft_atoi(info[2]);
	object->c = get_double_arr(info[3]);
	object->refl = ft_atod(info[4]);
	if (d)
		get_direction(info[5], object);
	object->color = ((color[0] << 16) | (color[1] << 8) | color[2]);
	ft_memdel((void **)&color);
}

void		init_objects(char **info, t_list **objects, int inf_len)
{
	t_object	object;

	ft_bzero(&object, sizeof(t_object));
	new_object(info, &object, inf_len);
	ft_lstadd(objects, ft_lstnew(&object, sizeof(t_object)));
}
