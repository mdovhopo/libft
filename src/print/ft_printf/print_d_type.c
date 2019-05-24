/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:03:24 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_num_prefix(t_token *token, int len, int64_t arg)
{
	int i;

	i = -1;
	if (token->flags & F_ZERO)
		print_sign(token, arg);
	if (token->width > MAX(abs(token->prec), len) && !(token->flags & F_MINUS))
		while (++i < token->width - MAX(abs(token->prec), len))
			ft_putchar((token->flags & F_ZERO)
					&& (token->prec == -1) ? '0' : ' ');
	if ((token->flags & F_SPACE) && !(token->flags & F_PLUS))
		if (arg >= 0)
			ft_putchar(token->flags & F_ZERO ? '0' : ' ');
	if (!(token->flags & F_ZERO))
		print_sign(token, arg);
}

uint32_t		type_d(t_token *token, va_list *ap)
{
	int64_t	arg;
	int		len;
	int		i;
	int		sign;

	set_arg_with_mods(token, &arg, ap);
	sign = ((token->flags & F_PLUS)
			|| (token->flags & F_SPACE) || (arg < 0) ? 1 : 0);
	len = (arg == INT64_MIN ? 19 : int_len(llabs(arg), 10));
	if (token->prec == 0 && arg == 0)
		len = 0;
	token->width -= sign;
	print_num_prefix(token, len, arg);
	i = -1;
	while (++i < token->prec - len)
		ft_putchar('0');
	if (token->prec != 0 || arg != 0)
		print_base_int64(arg == INT64_MIN ? INT64_MIN : llabs(arg), 10, 0);
	i = -1;
	if (token->width > MAX(abs(token->prec), len) && token->flags & F_MINUS)
		while (++i < token->width - MAX(abs(token->prec), len))
			ft_putchar(' ');
	return (MAX(token->width + sign, sign + MAX(token->prec, len)));
}
