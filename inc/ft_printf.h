/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:22:48 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/24 14:43:59 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <math.h>

# define STD_NULL_MSG "(null)"

/*
** h hh l ll L mods implied
*/

# define MODS_AMOUNT 5

/*
** BIT MASK
** ll " " #0-+ lLhH
**  0  0  0000 0000
*/

typedef enum	e_fmask
{
	F_LONGLONG = 0x200,
	F_SPACE = 0x100,
	F_HASH = 0x80,
	F_ZERO = 0x40,
	F_MINUS = 0x20,
	F_PLUS = 0x10,
	F_LONG = 0x08,
	F_LONGF = 0x04,
	F_SHORT = 0x02,
	F_SHORTSHORT = 0x1,
}				t_fmask;

typedef struct	s_token
{
	uint32_t	flags;
	uint32_t	type;
	int32_t		width;
	int32_t		prec;
	char		*str;
}				t_token;

/*
** main functions
*/

int				ft_printf(const char *fmt, ...);
uint32_t		print_format(char *str, va_list *ap);
void			parse_format(t_token *token);
uint32_t		handle_token(t_token *token, va_list *ap);

/*
** types handlers
*/

uint32_t		type_c(t_token *token, va_list *ap);
uint32_t		type_s(t_token *token, va_list *ap);
uint32_t		type_p(t_token *token, va_list *ap);
uint32_t		type_d(t_token *token, va_list *ap);
uint32_t		type_o(t_token *token, va_list *ap);
uint32_t		type_u(t_token *token, va_list *ap);
uint32_t		type_x(t_token *token, va_list *ap);
uint32_t		type_f(t_token *token, va_list *ap);

/*
** Utils
*/

# define MAX(a, b) (a > b ? a : b)

size_t			int_len(uint64_t n, int64_t base);
void			set_arg_with_mods(t_token *token, int64_t *arg, va_list *ap);
void			set_u_arg_with_mods(t_token *token, uint64_t *arg, va_list *ap);
void			print_base_int64(int64_t n, int64_t base, int lower_case);
void			print_sign(t_token *token, int64_t arg);
void			ft_putfloat(long double n, uint32_t prec);

#endif
