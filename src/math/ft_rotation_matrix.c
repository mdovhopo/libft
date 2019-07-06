/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:10:19 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/06/29 15:10:21 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Angle in radians
*/

t_mat4	mat_rotate_x(t_mat4 m, float angle)
{
	t_mat4	rot;

	ft_bzero(&rot, sizeof(t_mat4));
	rot[0] = 1;
	rot[5] = cos(angle);
	rot[6] = -sin(angle);
	rot[9] = -rot[6];
	rot[10] = rot[5];
	rot[15] = 1;
	return (mat_mult(m, rot));
}

t_mat4	mat_rotate_y(t_mat4 m, float angle)
{
	t_mat4	rot;

	ft_bzero(&rot, sizeof(t_mat4));
	rot[0] = cos(angle);
	rot[2] = sin(angle);
	rot[5] = 1;
	rot[8] = -rot[2];
	rot[10] = rot[0];
	rot[15] = 1;
	return (mat_mult(m, rot));
}

t_mat4	mat_rotate_z(t_mat4 m, float angle)
{
	t_mat4	rot;

	ft_bzero(&rot, sizeof(t_mat4));
	rot[0] = cos(angle);
	rot[1] = -sin(angle);
	rot[4] = -rot[1];
	rot[5] = rot[0];
	rot[10] = 1;
	rot[15] = 1;
	return (mat_mult(m, rot));
}

/*
** Rotation around axis by angle
*/

t_mat4	mat_rotate(t_mat4 m, t_vec4 axis, float angle)
{
	t_mat4	rot;
	t_vec4	r;
	float	c;
	float	s;
	float	c_inv;

	r = vec_unit(axis);
	c = cos(angle);
	s = sin(angle);
	c_inv = 1 - c;
	ft_bzero(&rot, sizeof(t_mat4));
	rot[0] = c + r[0] * r[0] * c_inv;
	rot[1] = r[0] * r[1] * c_inv - r[2] * s;
	rot[2] = r[0] * r[2] * c_inv + r[1] * s;
	
	rot[4] = r[1] * r[0] * c_inv + r[2] * s;
	rot[5] = c + r[1] * r[1] * c_inv;
	rot[6] = r[1] * r[2] * c_inv - r[0] * s;

	rot[8] = r[2] * r[0] * c_inv - r[1] * s;
	rot[9] = r[2] * r[1] * c_inv + r[0] * s;
	rot[10] = c + r[2] * r[2] * c_inv;
	
	rot[15] = 1;
	return (mat_mult(m, rot));
}
