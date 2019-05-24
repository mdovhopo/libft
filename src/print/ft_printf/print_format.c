/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:32:45 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	print_format(char *str, va_list *ap)
{
	t_token	*token;
	size_t	len;

	len = 0;
	token = (t_token*)ft_memalloc(sizeof(token));
	token->str = str;
	token->prec = -1;
	while (*token->str)
	{
		if (*token->str == '%')
		{
			parse_format(token);
			len += handle_token(token, ap);
			continue ;
		}
		ft_putchar(*token->str);
		token->str++;
		len++;
	}
	len += 0;
	free(token);
	return (len);
}
