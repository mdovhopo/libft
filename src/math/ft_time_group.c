/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:40:19 by tryckylake        #+#    #+#             */
/*   Updated: 2019/08/07 14:55:36 by tryckylake       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

clock_t _g_start;

void	ft_time_start()
{
	_g_start = clock();
}

void	ft_time_end(const char *name)
{
	double cpu_time_used;
	clock_t end;
	end = clock();
	cpu_time_used = ((double) (end - _g_start)) / CLOCKS_PER_SEC * 1000;
	printf("%s: [%fms]\n", name, cpu_time_used);
}
