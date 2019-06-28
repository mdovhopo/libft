#include "libft.h"

mat4	mat_identity()
{
	mat4 m;

	ft_bzero(&m, sizeof(mat4));
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
	return (m);
}

mat4	mat_scale(mat4 m, vec4 v)
{
	mat4 scale;

	ft_bzero(&scale, sizeof(mat4));
	scale[0] = v[0];
	scale[5] = v[1];
	scale[10] = v[2];
	scale[15] = 1;
	return (mat_mult(m, scale));
}

mat4	mat_translate(mat4 m, vec4 v)
{
	mat4 trans;

	trans = mat_identity();
	trans[3] = v[0];
	trans[7] = v[1];
	trans[11] = v[2];
	return (mat_mult(m, trans));
}
