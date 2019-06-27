/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:32:54 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		set_float_arg_with_mods(t_token *token,
											long double *arg, va_list *ap)
{
	if (token->flags & F_LONGF)
		*arg = (long double)va_arg(*ap, long double);
	else
		*arg = (double)va_arg(*ap, double);
}

static void		print_num_prefix(t_token *token, long double n, int len)
{
	int i;

	i = -1;
	if (token->flags & F_ZERO)
		print_sign(token, (int64_t)n);
	if (n > 0 && (token->flags & F_SPACE) && !(token->flags & F_PLUS))
		ft_putchar(' ');
	if (!(token->flags & F_MINUS))
		while (++i < token->width - len
								- (token->flags & F_PLUS || n < 0 ? 1 : 0))
			ft_putchar(token->flags & F_ZERO ? '0' : ' ');
	if (!(token->flags & F_ZERO))
		print_sign(token, (int64_t)n);
}

uint32_t		type_f(t_token *token, va_list *ap)
{
	long double	n;
	int			len;
	int			i;
	int			sign;

	set_float_arg_with_mods(token, &n, ap);
	sign = ((token->flags & F_PLUS) || token->flags & F_SPACE || n < 0) ? 1 : 0;
	if (token->prec == -1)
		token->prec = 6;
	len = int_len((uint64_t)fabsl(n), 10) + token->prec
											+ (token->prec == 0 ? 0 : 1);
	print_num_prefix(token, n, len);
	ft_putfloat(n, token->prec);
	i = -1;
	if (token->flags & F_MINUS)
		while (++i < token->width - len
							- (token->flags & F_PLUS || n < 0 ? 1 : 0))
			ft_putchar(' ');
	return (MAX(token->width, len + sign));
}

uint32_t		type_f_custom_param(t_token *token, void *param)
{
	float		n;
	int			len;
	int			i;
	int			sign;

	n = *(float*)param;
	sign = ((token->flags & F_PLUS) || token->flags & F_SPACE || n < 0) ? 1 : 0;
	if (token->prec == -1)
		token->prec = 6;
	len = int_len((uint64_t)fabsl(n), 10) + token->prec
											+ (token->prec == 0 ? 0 : 1);
	print_num_prefix(token, n, len);
	ft_putfloat(n, token->prec);
	i = -1;
	if (token->flags & F_MINUS)
		while (++i < token->width - len
							- (token->flags & F_PLUS || n < 0 ? 1 : 0))
			ft_putchar(' ');
	return (MAX(token->width, len + sign));
}
