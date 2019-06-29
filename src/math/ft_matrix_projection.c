/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:07:30 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/06/29 16:41:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** fov in degrees
*/

mat4	mat_perspective(float fov, float far, float near)
{
	mat4	out;
	float	scale;

	ft_bzero(&out, sizeof(mat4));
	scale = 1 / tan(DEG_TO_RAD(fov / 2));
	out[0] = scale;
	out[5] = scale;
	out[10] = - (far / (far - near));
	out[11] = -1;
	out[14] = - (far * near / (far - near));
	return (out);
}