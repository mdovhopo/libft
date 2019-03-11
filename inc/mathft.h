/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:06:52 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/11 16:07:02 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

# include <math.h>

#ifndef M_PI_180
# define M_PI_180 0.01745329251
#endif

typedef struct	s_vec
{
	double x;
	double y;
	double z;
}				t_vec;

void			ft_show_binary(unsigned int x);

/*
** @return: int representation of color from r g b params
*/

int				ft_rgb(int r, int g, int b);

/*
** returns value, converted from range a.x - a.y
** to b.x - b.y
*/

double			ft_map(double s, t_vec a, t_vec b);

/*
** vector calculations
*/

t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_mult(t_vec v, float x);
float			vec_dot(t_vec v1, t_vec v2);
t_vec			vec_cross(t_vec v1, t_vec v2);
t_vec			vec_mult_vec(t_vec v1, t_vec v2);
t_vec			vec_add_vec(t_vec v1, t_vec v2);
t_vec			vec_sub_vec(t_vec v1, t_vec v2);
t_vec			vec_clamp(float lo, float hi, t_vec v);

/*
** same as normilizing vector
*/

t_vec			vec_unit(t_vec v);
float			vec_mag(t_vec v);

/*
** for comparing vectors magnitude.
** it performs better because you won't use sqrt
*/

float			vec_mag_squared(t_vec v);

float			clamp(float lo, float hi, float v);
int				solve_qudric(t_vec params, float *x1, float *x2);
float			mix(float a, float b, float mix);

#endif
