/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:06:45 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/05/26 13:56:33 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define END_IS_ENDL(x) (x == '\n' ? 1 : 0)
# define END_IS_NULL(x) (x == '\0' ? 1 : 0)
# define CHECK_ERRORS(fd ,line, buff) (fd < 0 || !line || read(fd, buff, 0) < 0)
# define CHECK_IF_EXIT(d, f_ch, r_b) ((d == NULL || f_ch == '\0') && r_b == 0)
# define ERROR -1
# define SUCCESS_END 0
# define BUFF_SIZE 4096

typedef struct	s_gnl
{
	int				fd;
	char			*data;
	struct s_gnl	*next;
}				t_gnl;

/*
** reads 1 line from fd per call and asign line to **line
** @return: 1 - if line was read
**			0 - if file ended
**			-1 - on error
*/

int				get_next_line(const int fd, char **line);

#endif
