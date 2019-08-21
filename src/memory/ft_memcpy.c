/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:12:57 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/07 17:23:53 by tryckylake       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_word(void *dst, const void *src, size_t n)
{
	size_t		max;
	int32_t		i;
	long long	*d;
	long long	*s;

	max = n / WORD_SIZE;
	i = -1;
	d = (long long *)dst;
	s = (long long *)src;
	while (++i < max)
		d[i] = s[i];
}

static void	copy_bytes(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	while (n--)
		*d++ = *s++;
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	shift;

	if (n > WORD_SIZE)
		copy_word(dst, src, n);
	if (n % WORD_SIZE > 0)
	{
		shift = n / WORD_SIZE * WORD_SIZE;
		copy_bytes(dst + shift, src + shift, n % WORD_SIZE);
	}
	return dst;
}
