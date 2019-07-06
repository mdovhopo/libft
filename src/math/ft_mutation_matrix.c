/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:10:26 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/06/29 15:10:27 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	mat_identity()
{
	t_mat4 m;

	ft_bzero(&m, sizeof(t_mat4));
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
	return (m);
}

t_mat4	mat_scale(t_mat4 m, t_vec4 v)
{
	t_mat4 scale;

	ft_bzero(&scale, sizeof(t_mat4));
	scale[0] = v[0];
	scale[5] = v[1];
	scale[10] = v[2];
	scale[15] = 1;
	return (mat_mult(m, scale));
}

t_mat4	mat_translate(t_mat4 m, t_vec4 v)
{
	t_mat4 trans;

	trans = mat_identity();
	trans[3] = v[0];
	trans[7] = v[1];
	trans[11] = v[2];
	return (mat_mult(m, trans));
}
