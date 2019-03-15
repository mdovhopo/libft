/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:19:19 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/13 19:21:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_wspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r');
}