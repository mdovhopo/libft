/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:23:45 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:41:06 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	return ((t_vec){v1[Y] * v2[Z] - v1[Z] * v2[Y],
					v1[Z] * v2[X] - v1[X] * v2[Z],
					v1[X] * v2[Y] - v1[Y] * v2[X]});
}

/*
** same as normilizing vector
*/

t_vec	vec_unit(t_vec v)
{
	return ((t_vec){
		v[X] * (1 / sqrt(vec_dot(v, v))),
		v[Y] * (1 / sqrt(vec_dot(v, v))),
		v[Z] * (1 / sqrt(vec_dot(v, v))),
		v[A] * (1 / sqrt(vec_dot(v, v)))
	});
}

double	vec_mag(t_vec v)
{
	return (sqrt(vec_dot(v, v)));
}

/*
** for comparing vectors magnitude.
** it performs better because you don't do sqrt
*/

double	vec_mag_squared(t_vec v)
{
	return (vec_dot(v, v));
}
