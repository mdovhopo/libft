/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_quadric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:51:16 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/11 14:54:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

/*
** use VEC(a, b, c, 0) to pass params to func
** if quadric doesnt have solutions
** VEC(0, 0, -1) returns otherwise,
** VEC(x1, x2, 1)
*/

t_vec4		ft_solve_qudric(t_vec4 params)
{
	float	disc;
	float	a;
	float	b;
	float	c;

	a = params[X];
	b = params[Y];
	c = params[Z];
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (VEC(0, 0, -1, 0));
	return (VEC((-b + sqrt(disc)) / (2 * a), (-b - sqrt(disc)) / (2 * a), 1, 0));
}
