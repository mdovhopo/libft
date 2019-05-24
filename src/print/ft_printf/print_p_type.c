/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:20:40 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_num_prefix(t_token *token, int len)
{
	int i;

	i = -1;
	if (token->width > token->prec
				&& (token->flags & F_ZERO))
		ft_putstr("0x");
	if (token->width > MAX(abs(token->prec), len) && !(token->flags & F_MINUS))
		while (++i < token->width - MAX(abs(token->prec), len) - 2)
			ft_putchar((token->flags & F_ZERO)
					&& (token->prec == -1) ? '0' : ' ');
	if (!(token->flags & F_ZERO))
		ft_putstr("0x");
	i = -1;
	if (token->width < token->prec)
		ft_putstr("0x");
	while (++i < token->prec - len)
		ft_putchar('0');
}

static void		print_base_uint64(uint64_t n, uint64_t base, int lower_case)
{
	char c;

	if (n > base - 1)
		print_base_uint64(n / base, base, lower_case);
	if (n % base < 10)
		c = n % base + '0';
	else
		c = n % base + 55 + (lower_case ? 32 : 0);
	ft_putchar(c);
}

uint32_t		type_p(t_token *token, va_list *ap)
{
	uint64_t	arg;
	int			len;
	int			i;

	token->flags |= F_HASH;
	token->flags |= F_LONGLONG;
	arg = va_arg(*ap, uint64_t);
	len = int_len(arg, 16);
	if (token->prec == 0 && arg == 0)
		len = 0;
	print_num_prefix(token, len);
	if (token->prec != 0 || arg != 0)
		print_base_uint64(arg, 16, 1);
	len += 2;
	i = -1;
	if (token->width > MAX(abs(token->prec), len) && token->flags & F_MINUS)
		while (++i < token->width - MAX(abs(token->prec), len))
			ft_putchar(' ');
	return (MAX(token->width, MAX(token->prec, len)));
}
