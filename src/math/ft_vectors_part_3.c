/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors_patr_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:18:28 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/08 12:18:47 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

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
