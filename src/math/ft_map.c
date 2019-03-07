/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:08:28 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/07 13:30:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** transforms value s from range a.x - a.y to value
** (witch returns) to range b.x - b.y
*/

double	ft_map(double s, t_vec a, t_vec b)
{
	return (b.x + (s - a.x) * (b.y - b.x) / (a.y - a.x));
}
