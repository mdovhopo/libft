/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:46:41 by tryckylake        #+#    #+#             */
/*   Updated: 2019/08/21 16:29:40 by tryckylake       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4	ft_get_triangle_normal(t_vec4 *edges)
{
	t_vec4	v1;
	t_vec4	v2;

	v1 = edges[1] - edges[0];
	v2 = edges[2] - edges[0];  
	return vec_cross(v1, v2);
}
