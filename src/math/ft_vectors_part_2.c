/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:26:03 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/07 13:31:33 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

/*
** same as normilizing vector
*/

t_vec	vec_unit(t_vec v)
{
	return (vec_mult(v, 1 / sqrt(vec_dot(v, v))));
}

float	vec_mag(t_vec v)
{
	return (sqrt(vec_dot(v, v)));
}

/*
** for comparing vectors magnitude.
** it performs better because you don't do sqrt
*/

float	vec_mag_squared(t_vec v)
{
	return (vec_dot(v, v));
}
