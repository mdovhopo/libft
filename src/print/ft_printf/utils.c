/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:57:59 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/24 16:13:23 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			set_arg_with_mods(t_token *token, int64_t *arg, va_list *ap)
{
	if (token->flags & F_SHORT)
		*arg = (int16_t)va_arg(*ap, int32_t);
	else if (token->flags & F_SHORTSHORT)
		*arg = (int8_t)va_arg(*ap, int32_t);
	else if (token->flags & F_LONG)
		*arg = va_arg(*ap, long int);
	else if (token->flags & F_LONGLONG)
		*arg = va_arg(*ap, long long int);
	else
		*arg = va_arg(*ap, int);
}

void			set_u_arg_with_mods(t_token *token, uint64_t *arg, va_list *ap)
{
	if (token->flags & F_SHORT)
		*arg = (uint16_t)va_arg(*ap, uint32_t);
	else if (token->flags & F_SHORTSHORT)
		*arg = (uint8_t)va_arg(*ap, uint32_t);
	else if (token->flags & F_LONG)
		*arg = va_arg(*ap, unsigned long int);
	else if (token->flags & F_LONGLONG)
		*arg = va_arg(*ap, unsigned long long int);
	else
		*arg = va_arg(*ap, unsigned int);
}

void			print_base_int64(int64_t n, int64_t base, int lower_case)
{
	char c;

	if (n == INT64_MIN && base == 10)
		return (ft_putstr("9223372036854775808"));
	if (n > base - 1)
		print_base_int64(n / base, base, lower_case);
	if (n % base < 10)
		c = n % base + '0';
	else
		c = n % base + 55 + (lower_case ? 32 : 0);
	ft_putchar(c);
}

void			print_sign(t_token *token, int64_t arg)
{
	if (token->flags & F_PLUS)
		if (arg >= 0)
			ft_putchar('+');
	if (arg < 0)
		ft_putchar('-');
}

void			print_sign_float(t_token *token, long double arg)
{
	if (token->flags & F_PLUS)
		if (arg >= 0)
			ft_putchar('+');
	if (arg < 0)
		ft_putchar('-');
}
