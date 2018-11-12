/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_vect2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:26:08 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/08 14:55:24 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2d	ft_sub_vect2d(t_vector2d v1, t_vector2d v2)
{
	ft_rev_vect2d(&v2);
	return (ft_add_vect2d(v1, v2));
}
