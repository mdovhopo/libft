/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:18 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/31 16:29:41 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/*
** \@return - random value 0.0f - 1.0f
*/

float	ft_rand()
{
	int	fd;
	int	rand;

	fd = open("/dev/random", O_RDONLY);
	read(fd, &rand, sizeof(int));
	close(fd);
	return ((rand / ((float)INT32_MAX) + 1 )/ 2);
}

/*
** \@param (int lo) - lower boundary generated random value
** \@param (int hi) - higher boundary generated random value
** \@return int value in range lo - hi
**
** Passing lo bigger than hi - has undefined behavior
*/

int		ft_rand_range(int lo, int hi)
{
	int			fd;
	uint32_t	rand;

	fd = open("/dev/random", O_RDONLY);
	read(fd, &rand, sizeof(uint32_t));
	close(fd);
	return (rand % (hi) * 2 + lo);
}