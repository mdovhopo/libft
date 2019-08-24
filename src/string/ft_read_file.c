/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:12:35 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/24 16:12:49 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*error_report(const char *msg)
{
	ft_printf("read_file error [%s]\n", msg);
	return (NULL);
}

char		*ft_read_file(const char *path)
{
	ssize_t		file_size;
	char		*buffer;
	int			fd;

	if ((file_size = ft_get_file_size(path)) < 0)
		return (error_report("Could not get file size :("));
	if ((buffer = (char*)malloc(file_size + 1)) == NULL)
		return (error_report("Could not alloc memory :("));
	buffer[file_size] = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (error_report("Could not open file :("));
	if (read(fd, buffer, file_size) < 0)
		return (error_report("Could not read from file :("));
	close(fd);
	return (buffer);
}
