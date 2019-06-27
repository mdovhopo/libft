#include "libft.h"

mat4	mat_mult(mat4 m1, mat4 m2)
{
	int32_t	i;
	int32_t	j;
	int32_t	k;
	mat4	m;

	ft_bzero(&m, sizeof(mat4));
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				m[i * 4 + j] += m1[i * 4 + k] * m2[k * 4 + j];
		}
	}
	return (m);
}

vec4	mat_mult_vec(mat4 m, vec4 v)
{
	vec4	out;
	int32_t	i;
	int32_t	k;

	ft_bzero(&out, sizeof(vec4));
	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
			out[i] += m[i * 4 + k] * v[k];
	}
	return (out);
}
