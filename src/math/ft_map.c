/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:08:28 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:40:45 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** transforms value s from range a[X] - a[Y] to value
** (witch returns) to range b[X] - b[Y]
*/

float	ft_map(float s, vec4 a, vec4 b)
{
	return (b[X] + (s - a[X]) * (b[Y] - b[X]) / (a[Y] - a[Y]));
}
