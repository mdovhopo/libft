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
** For some reasons when math.h is included,
** no math constants is defined, so i defined them by myself
*/

#ifndef M_PI
# define M_E		2.7182818284590452354	/* e */
# define M_LOG2E	1.4426950408889634074	/* log_2 e */
# define M_LOG10E	0.43429448190325182765	/* log_10 e */
# define M_LN2		0.69314718055994530942	/* log_e 2 */
# define M_LN10		2.30258509299404568402	/* log_e 10 */
# define M_PI		3.14159265358979323846	/* pi */
# define M_PI_2		1.57079632679489661923	/* pi/2 */
# define M_PI_4		0.78539816339744830962	/* pi/4 */
# define M_1_PI		0.31830988618379067154	/* 1/pi */
# define M_2_PI		0.63661977236758134308	/* 2/pi */
# define M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
# define M_SQRT2	1.41421356237309504880	/* sqrt(2) */
# define M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */
#endif

/*
** Angle transformation
*/

# define RAD_TO_DEG(angle) (angle * (180.0f / M_PI))
# define DEG_TO_RAD(angle) (angle * (M_PI / 180.0f))

typedef enum	e_axis
{
	X = 0,
	Y = 1,
	Z = 2,
	A = 3
}				t_axis;

/*
** I had to define this types this way, due to 42 norminette
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

/*
** Matrix
*/

mat4	mat_mult(mat4 m1, mat4 m2);
vec4	mat_mult_vec(mat4 m, vec4 v);

/*
** Mutate matrix
*/

mat4	mat_identity(void);
mat4	mat_scale(mat4 m, vec4 v);
mat4	mat_translate(mat4 m, vec4 v);
mat4	mat_rotate_x(mat4 m, float angle);
mat4	mat_rotate_y(mat4 m, float angle);
mat4	mat_rotate_z(mat4 m, float angle);
mat4	mat_rotate(mat4 m, vec4 r, float angle);

#endif
