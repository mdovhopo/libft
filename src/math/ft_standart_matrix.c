#include "libft.h"

mat4	mat_identity()
{
	return (mat_scale(VEC(1, 1, 1, 1)));
}

mat4	mat_scale(vec4 v)
{
	mat4 m;

	ft_bzero(&m, sizeof(mat4));
	m[0] = v[0];
	m[5] = v[1];
	m[10] = v[2];
	m[15] = 1;
	return (m);
}

mat4	mat_translation(vec4 v)
{
	mat4 m;

	m = mat_identity();
	m[3] = v[0];
	m[7] = v[1];
	m[11] = v[2];
	return (m);
}
