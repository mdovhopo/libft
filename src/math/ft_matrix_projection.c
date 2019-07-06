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

// t_mat4	mat_ortho(float r, float l, float t, float b, float near, float far)
// {

// }
