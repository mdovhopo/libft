/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:05:51 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/24 16:05:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat4	mat_mult(t_mat4 m1, t_mat4 m2)
{
	int32_t	i;
	int32_t	j;
	int32_t	k;
	t_mat4	m;

	ft_bzero(&m, sizeof(t_mat4));
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				m[i * 4 + j] += m1[i * 4 + k] * m2[k * 4 + j];
		}
	}
	return (m);
}

t_vec4	mat_mult_vec(t_mat4 m, t_vec4 v)
{
	t_vec4	out;
	int32_t	i;
	int32_t	k;

	ft_bzero(&out, sizeof(t_vec4));
	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
			out[i] += m[i * 4 + k] * v[k];
	}
	return (out);
}
