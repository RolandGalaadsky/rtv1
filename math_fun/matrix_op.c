/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:11:59 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:12:00 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	**get_zero_matrix(void)
{
	double	**matrix;
	int		i;

	matrix = (double **)ft_memalloc(sizeof(double *) * 3);
	check_malloc(matrix);
	i = 0;
	while (i < 3)
	{
		matrix[i] = get_zero_vec();
		i++;
	}
	return (matrix);
}

double	**trans_matrix(double **matrix)
{
	double	**res;
	int		i;
	int		j;

	i = 0;
	res = get_zero_matrix();
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res[j][i] = matrix[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

double	**mult_matrix(double **matrix1, double **matrix2)
{
	double	**res;
	double	**trans;
	int		i;
	int		j;

	res = get_zero_matrix();
	trans = trans_matrix(matrix2);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res[i][j] = dot(matrix1[i], trans[j]);
			j++;
		}
		i++;
	}
	del_matrix(&trans);
	return (res);
}
