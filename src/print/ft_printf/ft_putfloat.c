/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:37:18 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO move this function to libft
*/

void	ft_putfloat(long double n, uint32_t prec)
{
	int64_t		int_part;
	long double	fraction;
	uint32_t	power;
	uint8_t		tmp;

	int_part = (int64_t)n;
	fraction = fabsl(n - (long double)int_part);
	print_base_int64(llabs(int_part), 10, 0);
	if (prec)
		ft_putchar('.');
	power = 0;
	while (++power <= prec)
	{
		fraction *= 10;
		tmp = (uint8_t)fraction % 10;
		fraction -= tmp;
		ft_putchar(tmp + '0');
	}
}
