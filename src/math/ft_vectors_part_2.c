/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:26:03 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/13 19:21:07 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

t_vec	vec_mult_vec(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vec	vec_add_vec(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vec	vec_sub_vec(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

/*
** same as normilizing vector
*/

t_vec	vec_unit(t_vec v)
{
	return (vec_mult(v, 1 / sqrt(vec_dot(v, v))));
}

t_vec	vec_clamp(float lo, float hi, t_vec v)
{
	v.x = clamp(lo, hi, v.x);
	v.y = clamp(lo, hi, v.y);
	v.z = clamp(lo, hi, v.z);
	return (v);
}
