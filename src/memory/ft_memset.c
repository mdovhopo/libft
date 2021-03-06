/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:28:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/07 17:05:01 by tryckylake       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*s;
	unsigned char	c1;

	c1 = (unsigned char)c;
	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = c1;
		i++;
	}
	return (b);
}
