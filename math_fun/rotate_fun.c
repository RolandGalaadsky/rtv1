/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:13:05 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:13:06 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	**get_rotate_x(double angle)
{
	double **res;

	res = get_zero_matrix();
	res[0][0] = 1;
	res[1][1] = cos(angle);
	res[1][2] = -sin(angle);
	res[2][1] = -res[1][2];
	res[2][2] = res[1][1];
	return (res);
}

double	**get_rotate_y(double angle)
{
	double **res;

	res = get_zero_matrix();
	res[0][0] = cos(angle);
	res[0][2] = sin(angle);
	res[1][1] = 1;
	res[2][0] = -res[0][2];
	res[2][2] = res[0][0];
	return (res);
}

double	**get_rotate_z(double angle)
{
	double **res;

	res = get_zero_matrix();
	res[0][0] = cos(angle);
	res[0][1] = -sin(angle);
	res[1][0] = -res[0][1];
	res[1][1] = res[0][0];
	res[2][2] = 1;
	return (res);
}

double	**get_rotate_matrix(char *info)
{
	double	*angles;
	double	**rotate_x;
	double	**rotate_y;
	double	**rotate_z;
	double	**rotate_matrix;

	angles = get_double_arr(info);
	rotate_x = get_rotate_x(angles[0] * DEGREE);
	rotate_y = get_rotate_y(angles[1] * DEGREE);
	rotate_z = get_rotate_z(angles[2] * DEGREE);
	rotate_matrix = mult_matrix(rotate_x, rotate_y);
	del_matrix(&rotate_x);
	del_matrix(&rotate_y);
	rotate_x = rotate_matrix;
	rotate_matrix = mult_matrix(rotate_matrix, rotate_z);
	del_matrix(&rotate_x);
	del_matrix(&rotate_z);
	ft_memdel((void **)&angles);
	return (rotate_matrix);
}

void	rotate(double *point, double **trans)
{
	double	buff[3];
	int		i;

	if (!trans)
		return ;
	i = 0;
	while (i < 3)
	{
		buff[i] = dot(point, trans[i]);
		i++;
	}
	ft_memcpy(point, buff, DOUB_ARR_SIZE);
	return ;
}
