/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalars_vector_fun.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:13:56 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:13:58 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	len(double *v)
{
	int		i;
	double	sq_len;

	sq_len = 0;
	i = 0;
	while (i < 3)
	{
		sq_len += SQUARE(v[i]);
		i++;
	}
	return (sqrt(sq_len));
}

double	dot(double *v, double *w)
{
	double	res;
	int		i;

	res = 0;
	i = 0;
	while (i < 3)
	{
		res += v[i] * w[i];
		i++;
	}
	return (res);
}
