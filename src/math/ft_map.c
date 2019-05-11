/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:08:28 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/11 15:13:38 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** transforms value s from range a[X] - a[Y] to value
** (witch returns) to range b[X] - b[Y]
*/

inline double	ft_map(double s, t_vec a, t_vec b)
{
	return (b[X] + (s - a[X]) * (b[Y] - b[X]) / (a[Y] - a[Y]));
}
