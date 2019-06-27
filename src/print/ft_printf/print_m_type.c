#include "libft.h"

uint32_t	type_m(t_token *token, va_list *ap)
{
	mat4		m;
	int32_t		i;
	int32_t		j;
	vec4		tmp_arg;
	uint32_t	len;

	len = 4;
	i = -1;
	m = (mat4)va_arg(*ap, mat4);
	while(++i < 4)
	{
		j = i * 4;
		tmp_arg = VEC(m[j], m[j + 1], m[j + 2], m[j + 3]);
		len += type_v_custom_param(token, (void*)&tmp_arg);
		ft_putchar('\n');
	}
	return (len);
}