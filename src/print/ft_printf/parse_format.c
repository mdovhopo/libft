/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:11:23 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:48:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		g_flags[] = "-+#0 ";
static const t_fmask	g_flags_mask[] = {
	F_MINUS, F_PLUS, F_HASH, F_ZERO, F_SPACE
};
static const char		g_types[] = "cspdiouxXf%vm";
static const char		*g_mods[] = { "h", "hh", "l", "ll", "L" };
static const t_fmask	g_mods_mask[] = {
	F_SHORT, F_SHORTSHORT, F_LONG,
	F_LONGLONG, F_LONGF
};

size_t					int_len(uint64_t n, int64_t base)
{
	size_t	len;

	len = 1;
	while (n / base > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

static int				find_modificator(t_token *token)
{
	int i;

	if (*token->str != 'h' && *token->str != 'l' && *token->str != 'L')
		return (0);
	i = -1;
	while (++i < MODS_AMOUNT)
	{
		if (ft_strstr(token->str, g_mods[i]))
		{
			token->flags |= g_mods_mask[i];
			token->str += ft_strlen(g_mods[i]);
			return (1);
		}
	}
	return (0);
}

static void				parse_width(t_token *token, uint8_t *parse_status)
{
	*parse_status = 1;
	token->width = ft_atoi(token->str);
	token->str += int_len(token->width, 10);
}

static void				parse_precision(t_token *token, uint8_t *parse_status)
{
	*parse_status = 2;
	token->prec = ft_atoi(token->str + 1);
	if (token->prec == 0 && *(token->str + 1) != '0')
		token->str -= 1;
	token->str += int_len(token->prec, 10) + 1;
}

void					parse_format(t_token *token)
{
	char	*c;
	uint8_t	parse_status;

	parse_status = 0;
	while (*(++token->str))
	{
		if (parse_status < 1 && (c = ft_strchr(g_flags, *token->str)))
			token->flags |= g_flags_mask[c - g_flags];
		if (ft_isdigit(*token->str) && *token->str != '0' && parse_status < 1)
			parse_width(token, &parse_status);
		if (*token->str == '.' && parse_status < 3)
			parse_precision(token, &parse_status);
		if (find_modificator(token))
			parse_status = 3;
		if (ft_strchr(g_types, *token->str))
		{
			token->type = ft_strchr(g_types, *token->str++) - g_types;
			return ;
		}
		if (*token->str == '\0')
			exit(-1);
	}
}
