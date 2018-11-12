/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:45:20 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/03 17:17:14 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_null(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return ((char *)NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else
		return (ft_strdup(s2));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		c_join;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (is_null(s1, s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *)malloc(len_s1 + len_s2 + 1);
	if (join)
	{
		c_join = 0;
		i = 0;
		while (s1[i] != '\0')
			join[c_join++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			join[c_join++] = s2[i++];
		join[c_join] = '\0';
	}
	return (join);
}
