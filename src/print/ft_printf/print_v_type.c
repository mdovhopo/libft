#include "libft.h"

uint32_t	type_v(t_token *token, va_list *ap)
{
	t_vec4		v;
	int32_t		i;
	uint32_t	len;
	float_t		tmp_arg;

	i = -1;
	len = 3;
	v = (t_vec4)va_arg(*ap, t_vec4);
	while (++i < 4)
	{
		tmp_arg = v[i];
		len += type_f_custom_param(token, (void*)&tmp_arg);
		i < 4 ? ft_putchar(' ') : NULL;
	}
	return (len);
}

uint32_t	type_v_custom_param(t_token *token, void *param)
{
	t_vec4		v;
	int32_t		i;
	uint32_t	len;
	float_t		tmp_arg;

	i = -1;
	len = 3;
	v = *(t_vec4*)param;
	while (++i < 4)
	{
		tmp_arg = v[i];
		len += type_f_custom_param(token, (void*)&tmp_arg);
		i < 4 ? ft_putchar(' ') : NULL;
	}
	return (len);
}