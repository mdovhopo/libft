/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_quadric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:51:16 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/07 13:56:47 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathft.h"

/*
** use VEC(a, b, c) to pass params to func
** returns 0 if quadric discr < 0
*/

int		solve_qudric(t_vec params, float *x0, float *x1)
{
	float discr;
	float q;

	discr = params.y * params.y - 4 * params.x * params.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.y / params.x;
		*x1 = *x1;
	}
	else
	{
		q = (params.y > 0) ? -0.5 * (params.y + sqrt(discr)) :
							-0.5 * (params.y - sqrt(discr));
		*x0 = q / params.x;
		*x1 = params.z / q;
	}
	return (1);
}
