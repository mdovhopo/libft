/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_quadric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:51:16 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/13 19:21:01 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

/*
** use VEC(a, b, c) to pass params to func
** if quadric doesnt have solutions
** VEC(0, 0, -1) returns otherwise,
** VEC(x1, x2, 1)
*/

t_vec		ft_solve_qudric(t_vec params)
{
	float	disc;
	float	a;
	float	b;
	float	c;

	a = params.x;
	b = params.y;
	c = params.z;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (VEC(0, 0, -1));
	return (VEC((-b + sqrt(disc)) / (2 * a), (-b - sqrt(disc)) / (2 * a), 1));
}
