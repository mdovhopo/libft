/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:21:13 by tryckylake        #+#    #+#             */
/*   Updated: 2019/07/28 17:22:25 by tryckylake       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_array_push(
			void *arr, void *elem, uint32_t elem_size, uint32_t arr_len)
{
	void	*mem;
	size_t	realloc_size;
	size_t	arr_size;

	realloc_size = elem_size * (arr_len + 1);
	arr_size = elem_size * arr_len;
	mem = realloc(arr, realloc_size);
	if (mem != NULL)
	{
		ft_memcpy(mem + arr_size, elem, elem_size);
		return mem;
	}
	mem = malloc(realloc_size);
	if (mem != NULL)
	{
		ft_memcpy(mem, arr, arr_size);
		ft_memcpy(mem + arr_size, elem, elem_size);
		free(arr);
		return (mem);
	}
	ft_printf(RED "ERROR" RESET "failed to push element to array");
	return (NULL);
}
