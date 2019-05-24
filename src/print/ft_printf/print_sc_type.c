/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sc_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:56:18 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t		type_c(t_token *token, va_list *ap)
{
	char	c;
	int		i;

	i = -1;
	if (token->type == 10)
		c = '%';
	else
		c = (char)va_arg(*ap, int32_t);
	if (token->width > 1 && !(token->flags & F_MINUS))
		while (++i < token->width - 1)
			ft_putchar(' ');
	ft_putchar(c);
	if (token->width > 1 && token->flags & F_MINUS)
		while (++i < token->width - 1)
			ft_putchar(' ');
	return (token->width ? token->width : 1);
}

uint32_t		type_s(t_token *token, va_list *ap)
{
	int		len;
	char	*str;
	int		i;

	i = -1;
	str = va_arg(*ap, char*);
	if (str == NULL)
		str = STD_NULL_MSG;
	len = ft_strlen(str);
	if (token->prec != -1)
		len = (token->prec <= len ? token->prec : len);
	if (token->width > len && !(token->flags & F_MINUS))
		while (++i < token->width - len)
			ft_putchar(token->flags & F_ZERO ? '0' : ' ');
	i = -1;
	while (++i < len)
		ft_putchar(str[i]);
	i = -1;
	if (token->width > len && token->flags & F_MINUS)
		while (++i < token->width - len)
			ft_putchar(token->flags & F_ZERO ? '0' : ' ');
	return (token->width > len ? token->width : len);
}
