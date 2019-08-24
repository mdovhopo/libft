/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:06:52 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/23 14:29:52 by tryckylake       ###   ########.fr       */
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

# define RAD_TO_DEG(angle) (angle * 180.0f / M_PI)
# define DEG_TO_RAD(angle) (angle * M_PI / 180.0f)

typedef enum	e_axis
{
	X = 0,
	Y = 1,
	Z = 2,
	A = 3
}				t_axis;

/*
** this matrix is written in row major order
** vec(d|i)4  4  float/double/int array that represents 4   component vector
** mat(d)4 - 16  float/double     array that represents 4x4 component matrix
*/

typedef float	__attribute__((vector_size(16)))	t_vec4;
typedef double	__attribute__((vector_size(32)))	t_vecd4;
typedef float	__attribute__((vector_size(64)))	t_mat4;
typedef double	__attribute__((vector_size(128)))	t_matd4;

typedef	uint32_t	t_veci3[3];

/*
** basic vector constructors
*/

# define VEC(x, y, z, w)	((t_vec4){x, y, z, w})
# define VEC3(x, y, z) 		((t_vec4){x, y, z, 1.0f})
# define VEC2(x, y) 		((t_vec4){x, y, 0.0f, 0.0f})

# define VECI3(x, y, z)		((t_veci3){x, y, z});

# define FLOAT_TO_VEC(n)		((t_vec4){n, n, n, 1.0f})

typedef union	u_color
{
	uint32_t	c;
	t_vec4		argb;
}				t_color;

void			ft_show_binary(unsigned int x);

/*
** transforms value s from range a[X] - a[Y] to value
** (witch returns) to range b[X] - b[Y]
*/

float			ft_map(float s, t_vec4 a, t_vec4 b);

/*
** vector calculations
*/

float			vec_dot(t_vec4 v1, t_vec4 v2);
t_vec4			vec_cross(t_vec4 v1, t_vec4 v2);
t_vec4			vec_clamp(float lo, float hi, t_vec4 v);
float			vec_mag(t_vec4 v);

/*
** same as normilizing vector
*/

t_vec4			vec_unit(t_vec4 v);

/*
** for comparing vectors magnitude.
** it performs better because you won't use sqrt
*/

float			vec_mag_squared(t_vec4 v);

float			clamp(float lo, float hi, float v);
float			loop(float lo, float hi, float v);
t_vec4			ft_solve_qudric(t_vec4 params);
float			mix(float a, float b, float mix);

/*
** random number generation
*/

float			ft_rand(void);
int				ft_rand_range(int lo, int hi);

/*
** Matrix
*/

t_mat4			mat_mult(t_mat4 m1, t_mat4 m2);
t_vec4			mat_mult_vec(t_mat4 m, t_vec4 v);

/*
** Mutate matrix
*/

t_mat4			mat_identity(void);
t_mat4			mat_scale(t_mat4 m, t_vec4 v);
t_mat4			mat_translate(t_mat4 m, t_vec4 v);
t_mat4			mat_rotate_x(t_mat4 m, float angle);
t_mat4			mat_rotate_y(t_mat4 m, float angle);
t_mat4			mat_rotate_z(t_mat4 m, float angle);
t_mat4			mat_rotate(t_mat4 m, t_vec4 r, float angle);

/*
** Projection Matrices
*/

t_mat4			mat_perspective(float fov, float asp, float near, float far);
t_mat4			mat_ortho(t_vec4 rlbt, float near, float far);

/*
** Camera stuff
*/

t_mat4			mat_look_at(t_vec4 pos, t_vec4 target, t_vec4 up);

/*
** Calculate normals
*/

t_vec4			ft_get_triangle_normal(t_vec4 *edges);

#endif
