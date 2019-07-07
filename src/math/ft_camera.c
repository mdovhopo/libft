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

// TODO make it works :3

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

t_mat4	mat_look_at(t_vec4 pos, t_vec4 target, t_vec4 up)
{
	t_mat4 rot;
	t_mat4 translate;
	t_vec4 cam_dir;
	t_vec4 cam_right;
	t_vec4 cam_up;
	int i;

	rot = mat_identity();
	translate = mat_identity();
	cam_dir = vec_unit(pos - target);
	cam_right = vec_unit(vec_cross(up, cam_dir));
	cam_up = vec_cross(cam_dir, cam_right);
	i = -1;
	translate[3] = -pos[0];
	translate[7] = -pos[1];
	translate[11] = -pos[2];
	while (++i < 3)
		rot[i] = cam_right[i];
	i = -1;
	while (++i < 3)
		rot[4 + i] = cam_up[i];
	i = -1;
	while(++i < 3)
		rot[8 + i] = cam_dir[i];
	return (mat_mult(rot, translate));
}
