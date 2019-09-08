/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:12:35 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/09/08 17:48:13 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ERR_MSG RED"ERROR: "RESET

static void	*error_report(const char *msg, const char *name)
{
	ft_printf("%s %s\n", msg, name);
	return (NULL);
}

char		*ft_read_file(const char *path)
{
	ssize_t		file_size;
	char		*buffer;
	int			fd;

	if ((file_size = ft_get_file_size(path)) < 0)
		return (error_report(ERR_MSG"Could not get file size."
				" (Probably it does not exist!)", path));
	if ((buffer = (char*)malloc(file_size + 1)) == NULL)
		return (error_report(ERR_MSG"Could not alloc memory", path));
	buffer[file_size] = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (error_report(ERR_MSG"Could not open file", path));
	if (read(fd, buffer, file_size) < 0)
		return (error_report(ERR_MSG"Could not read from file", path));
	close(fd);
	return (buffer);
}
