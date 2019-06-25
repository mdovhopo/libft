/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_small_fnc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:48:41 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:41:08 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

float	clamp(float lo, float hi, float v)
{
	return (fmax(lo, fmin(hi, v)));
}

vec4	vec_clamp(float lo, float hi, vec4 v)
{
	return ((vec4){
		clamp(lo, hi, v[X]),
		clamp(lo, hi, v[Y]),
		clamp(lo, hi, v[Z]),
		clamp(lo, hi, v[A]),
	});
}

float	mix(float a, float b, float mix)
{
	return (b * mix + a * (1 - mix));
}
