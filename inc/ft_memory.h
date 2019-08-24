/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:09:26 by tryckylake        #+#    #+#             */
/*   Updated: 2019/08/24 15:38:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

# define WORD_SIZE sizeof(int64_t)

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst,
			const void *src, size_t n);
void	*ft_memccpy(void *dst,
			const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp (const void *s1, const void *s2, size_t n);

/*
** Memory utils not from stdlib
*/

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_array_push(void *arr,
						void *elem,
						uint32_t elem_size,
						uint32_t arr_len);
#endif
