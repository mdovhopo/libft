/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:06:52 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/31 16:18:44 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

# include <math.h>
# include <stdint.h>

/*
** "constructor" for t_vec object
*/

# define VEC(x, y, z) ((t_vec){x, y, z, 0})

# ifndef M_PI_180
#  define M_PI_180 0.01745329251
# endif

typedef enum	e_axis
{
	X = 0,
	Y = 1,
	Z = 2,
	A = 3
}				t_axis;

typedef	double __attribute__((vector_size(32)))	t_vec;

typedef union	u_color
{
	uint32_t	c;
	t_vec		argb;
}				t_color;

void			ft_show_binary(unsigned int x);

/*
** transforms value s from range a[X] - a[Y] to value
** (witch returns) to range b[X] - b[Y]
*/

double			ft_map(double s, t_vec a, t_vec b);

/*
** vector calculations
*/

double			vec_dot(t_vec v1, t_vec v2);
t_vec			vec_cross(t_vec v1, t_vec v2);
t_vec			vec_clamp(float lo, float hi, t_vec v);
double			vec_mag(t_vec v);

/*
** same as normilizing vector
*/

t_vec			vec_unit(t_vec v);

/*
** for comparing vectors magnitude.
** it performs better because you won't use sqrt
*/

double			vec_mag_squared(t_vec v);

float			clamp(float lo, float hi, float v);
t_vec			ft_solve_qudric(t_vec params);
float			mix(float a, float b, float mix);

/*
** random number generation
*/

float	ft_rand(void);
int		ft_rand_range(int lo, int hi);

#endif
