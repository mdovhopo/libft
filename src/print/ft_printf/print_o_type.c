/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:04:44 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_num_prefix(t_token *token, int len, int64_t arg)
{
	int i;

	i = -1;
	if (token->width > MAX(abs(token->prec), len) && !(token->flags & F_MINUS))
		while (++i < token->width - MAX(abs(token->prec), len)
									- (token->flags & F_HASH ? 1 : 0))
			ft_putchar((token->flags & F_ZERO)
					&& (token->prec == -1) ? '0' : ' ');
	i = -1;
	while (++i < token->prec - len)
		ft_putchar('0');
	if (token->flags & F_HASH && (token->prec != -1 || arg != 0))
		ft_putchar('0');
}

uint32_t		type_o(t_token *token, va_list *ap)
{
	uint64_t	arg;
	int			len;
	int			i;

	set_u_arg_with_mods(token, &arg, ap);
	len = int_len(arg, 8);
	if (token->prec == 0 && arg == 0)
		len = 0;
	print_num_prefix(token, len, arg);
	if (token->prec != 0 || arg != 0)
		print_base_int64(arg, 8, 0);
	if ((token->flags & F_HASH) && (token->prec == 0 && len++))
		ft_putchar('0');
	i = -1;
	if (token->width > MAX(abs(token->prec), len) && token->flags & F_MINUS)
		while (++i < token->width - MAX(abs(token->prec), len)
				- (token->flags & F_HASH ? 1 : 0))
			ft_putchar(' ');
	return (MAX(token->width, MAX(token->prec, len)));
}
