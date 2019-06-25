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

/*
** I had to define this types this due to 42 norminette
** so, vec(d)4 - 4  float/float array that represents 4   component vector
** 	   mat(d)4 - 16 float/float array that represents 4x4 component matrix
*/

# define VEC4  typedef float __attribute__((vector_size(16)))	vec4;
# define VECD4 typedef float __attribute__((vector_size(32)))	vecd4;
# define MAT4  typedef float __attribute__((vector_size(64)))	mat4;
# define MATD4 typedef float __attribute__((vector_size(128)))	matd4;

VEC4
VECD4
MAT4
MATD4

/*
** basic vector constructor
*/

# define VEC(x, y, z, w) ((vec4){x, y, z, w})

typedef union	u_color
{
	uint32_t	c;
	vec4		argb;
}				t_color;

void			ft_show_binary(unsigned int x);

/*
** transforms value s from range a[X] - a[Y] to value
** (witch returns) to range b[X] - b[Y]
*/

float			ft_map(float s, vec4 a, vec4 b);

/*
** vector calculations
*/

float			vec_dot(vec4 v1, vec4 v2);
vec4			vec_cross(vec4 v1, vec4 v2);
vec4			vec_clamp(float lo, float hi, vec4 v);
float			vec_mag(vec4 v);

/*
** same as normilizing vector
*/

vec4			vec_unit(vec4 v);

/*
** for comparing vectors magnitude.
** it performs better because you won't use sqrt
*/

float			vec_mag_squared(vec4 v);

float			clamp(float lo, float hi, float v);
vec4			ft_solve_qudric(vec4 params);
float			mix(float a, float b, float mix);

/*
** random number generation
*/

float	ft_rand(void);
int		ft_rand_range(int lo, int hi);

#endif
