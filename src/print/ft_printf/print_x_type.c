/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:04:18 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_num_prefix(t_token *token, uint64_t arg, int len)
{
	int i;

	i = -1;
	if ((token->flags & F_HASH) && token->width > token->prec
				&& arg != 0 && (token->flags & F_ZERO))
		ft_putstr(token->type == 7 ? "0x" : "0X");
	if (token->width > MAX(abs(token->prec), len) && !(token->flags & F_MINUS))
		while (++i < token->width - MAX(abs(token->prec), len)
								- (token->flags & F_HASH ? 2 : 0))
			ft_putchar((token->flags & F_ZERO)
					&& (token->prec == -1) ? '0' : ' ');
	if (!(token->flags & F_ZERO) && (token->flags & F_HASH) && arg != 0)
		ft_putstr(token->type == 7 ? "0x" : "0X");
	i = -1;
	if (arg == 0)
		token->flags &= ~F_HASH;
	if ((token->flags & F_HASH) && token->width < token->prec && arg != 0)
		ft_putstr(token->type == 7 ? "0x" : "0X");
	while (++i < token->prec - len)
		ft_putchar('0');
}

uint32_t		type_x(t_token *token, va_list *ap)
{
	uint64_t	arg;
	int			len;
	int			i;

	set_u_arg_with_mods(token, &arg, ap);
	len = int_len(arg, 16);
	if (token->prec == 0 && arg == 0)
		len = 0;
	print_num_prefix(token, arg, len);
	if (token->prec != 0 || arg != 0)
		print_base_int64(arg, 16, token->type == 7);
	if (token->flags & F_HASH)
		len += 2;
	i = -1;
	if (token->width > MAX(abs(token->prec), len) && token->flags & F_MINUS)
		while (++i < token->width - MAX(abs(token->prec), len))
			ft_putchar(' ');
	return (MAX(token->width, MAX(token->prec, len)));
}
