/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:13:00 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** types handler jump table
*/

static uint32_t (*g_type_handlers[])(t_token*, va_list*) = {
	&type_c,
	&type_s,
	&type_p,
	&type_d,
	&type_d,
	&type_o,
	&type_u,
	&type_x,
	&type_x,
	&type_f,
	&type_c,
	&type_v,
	&type_m
};

uint32_t		handle_token(t_token *token, va_list *ap)
{
	uint32_t	len;
	char		*s_tmp;

	s_tmp = token->str;
	len = g_type_handlers[token->type](token, ap);
	ft_bzero(token, sizeof(t_token));
	token->str = s_tmp;
	token->prec = -1;
	return (len);
}
