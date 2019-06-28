#include "libft.h"

/*
** Angle in radians
*/

mat4	mat_rotate_x(mat4 m, float angle)
{
	mat4	rot;

	ft_bzero(&rot, sizeof(mat4));
	rot[0] = 1;
	rot[5] = cos(angle);
	rot[6] = -sin(angle);
	rot[9] = -rot[6];
	rot[10] = rot[5];
	rot[15] = 1;
	return (mat_mult(m, rot));
}

mat4	mat_rotate_y(mat4 m, float angle)
{
	mat4	rot;

	ft_bzero(&rot, sizeof(mat4));
	rot[0] = cos(angle);
	rot[2] = sin(angle);
	rot[5] = 1;
	rot[8] = -rot[2];
	rot[10] = rot[0];
	rot[15] = 1;
	return (mat_mult(m, rot));
}

mat4	mat_rotate_z(mat4 m, float angle)
{
	mat4	rot;

	ft_bzero(&rot, sizeof(mat4));
	rot[0] = cos(angle);
	rot[1] = -sin(angle);
	rot[4] = -rot[1];
	rot[5] = rot[0];
	rot[10] = 1;
	rot[15] = 1;
	return (mat_mult(m, rot));
}

/*
** Rotation around r by angle
*/

mat4	mat_rotate(mat4 m, vec4 r, float angle)
{
	mat4	rot;
	float	c;
	float	s;
	float	c_inv;

	c = cos(angle);
	s = sin(angle);
	c_inv = 1 - c;
	ft_bzero(&rot, sizeof(mat4));
	rot[0] = c + r[0] * r[0] * c_inv;
	rot[1] = r[0] * r[1] * c_inv - r[2] * s;
	rot[2] = r[0] * r[2] * c_inv + r[1] * s;
	rot[4] = r[1] * r[0] * c_inv + r[2] * s;
	rot[5] = c + r[1] * r[1] * c_inv;
	rot[6] = r[1] * r[2] * c_inv - r[0] * s;
	rot[8] = r[2] * r[0] * c_inv - r[1] * s;
	rot[9] = r[2] * r[1] * c_inv + r[0] * s;
	rot[10] = c + r[2] * r[2] * c_inv;
	rot[15] = 1;
	return (mat_mult(m, rot));
}
