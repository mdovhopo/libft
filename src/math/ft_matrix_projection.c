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

t_mat4	mat_perspective(float fov, float aspect, float near, float far)
{
	t_mat4	out;
	float	scale;

	ft_bzero(&out, sizeof(t_mat4));
	scale = tan(fov / 2);
	out[0] = 1 / (scale * aspect);
	out[5] = 1 / scale;
	out[10] = (far + near) / (near - far);
	out[11] = (2 * far * near) / (near - far);
	out[14] = -1 ;
	return (out);
}

/*
** rlbt is a vector with left right top botton values
*/

// TODO make it work :3

t_mat4	mat_ortho(t_vec4 lrtb, float near, float far)
{
	t_mat4 out;

	ft_bzero(&out, sizeof(t_mat4));
	out[0] = 2.0f / (lrtb[1] - lrtb[0]);
	out[3] = - (lrtb[1] + lrtb[0]) / (lrtb[1] - lrtb[0]);
	out[5] = 2.0f / (lrtb[2] - lrtb[3]);
	out[7] = - (lrtb[2] + lrtb[3]) / (lrtb[2] - lrtb[3]);
	out[10] = -2.0f / (far - near);
	out[11] = - (far + near) / (far - near);
	out[15] = 1.0f;
	return (out);
}
