/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:40:19 by tryckylake        #+#    #+#             */
/*   Updated: 2019/08/24 16:05:38 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

clock_t g_start;

void	ft_time_start(void)
{
	g_start = clock();
}

void	ft_time_end(const char *name)
{
	double	cpu_time_used;
	clock_t	end;

	end = clock();
	cpu_time_used = ((double)(end - g_start)) / CLOCKS_PER_SEC * 1000;
	ft_printf("%s: [%fms]\n", name, cpu_time_used);
}
