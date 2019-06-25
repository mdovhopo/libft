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

float	vec_dot(vec4 v1, vec4 v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

vec4	vec_cross(vec4 v1, vec4 v2)
{
	return ((vec4){v1[Y] * v2[Z] - v1[Z] * v2[Y],
					v1[Z] * v2[X] - v1[X] * v2[Z],
					v1[X] * v2[Y] - v1[Y] * v2[X]});
}

/*
** same as normilizing vector
*/

vec4	vec_unit(vec4 v)
{
	return ((vec4){
		v[X] * (1 / sqrt(vec_dot(v, v))),
		v[Y] * (1 / sqrt(vec_dot(v, v))),
		v[Z] * (1 / sqrt(vec_dot(v, v))),
		v[A] * (1 / sqrt(vec_dot(v, v)))
	});
}

float	vec_mag(vec4 v)
{
	return (sqrt(vec_dot(v, v)));
}

/*
** for comparing vectors magnitude.
** it performs better because you don't do sqrt
*/

float	vec_mag_squared(vec4 v)
{
	return (vec_dot(v, v));
}
