/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:13:00 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/24 16:13:04 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_get_file_size(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
		return (st.st_size);
	else
		return (-1);
}
