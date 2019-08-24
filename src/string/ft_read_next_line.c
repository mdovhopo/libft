/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 01:43:55 by tryckylake        #+#    #+#             */
/*   Updated: 2019/08/24 16:12:22 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** High preformanse version of get_next_line
** reads line from const char *file_name, allocate memory
** for it, copy it to this memory, and assign
** it to char **line
*/

int			ft_read_next_line(const char *file_name, char **line)
{
	static int32_t	file_size = -1;
	static char		*file_data = NULL;
	static size_t	file_pointer = 0;
	size_t			line_size;

	if (file_pointer > file_size)
	{
		free(file_data);
		return (0);
	}
	if (file_size < 0)
		if ((file_size = ft_get_file_size(file_name)) < 0)
			return (-1);
	if (file_data == NULL)
		file_data = ft_read_file(file_name);
	line_size = 0;
	while (
		file_data[line_size + file_pointer] &&
		file_data[line_size + file_pointer] != '\n')
		line_size++;
	*line = (char*)malloc(sizeof(char) * (line_size + 1));
	(*line)[line_size] = '\0';
	ft_memcpy(*line, file_data + file_pointer, line_size);
	file_pointer += line_size + 1;
	return (1);
}
