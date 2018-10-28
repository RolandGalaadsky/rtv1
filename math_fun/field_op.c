/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:20:36 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:20:38 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	*mult_on_sc(double *v, double sc)
{
	int		i;
	double	*w;

	i = 0;
	w = get_zero_vec();
	while (i < 3)
	{
		w[i] = sc * v[i];
		i++;
	}
	return (w);
}

double	*add_sc(double *v, double *w, double scale)
{
	double	*res;
	int		i;

	res = get_zero_vec();
	i = 0;
	while (i < 3)
	{
		res[i] = v[i] + scale * w[i];
		i++;
	}
	return (res);
}

double	*add(double *v, double *w)
{
	return (add_sc(v, w, 1));
}

double	*sub(double *v, double *w)
{
	return (add_sc(v, w, -1));
}
