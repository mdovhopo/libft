/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_small_fnc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:48:41 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/07 13:58:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

float	clamp(float lo, float hi, float v)
{
	return (fmax(lo, fmin(hi, v)));
}

float	mix(float a, float b, float mix)
{
	return (b * mix + a * (1 - mix));
}
