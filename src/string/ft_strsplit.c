/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tryckylake <tryckylake@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:11 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/08/03 13:16:14 by tryckylake       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_char(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;
	int		words;

	words = ft_count_words(s, c);
	printf("Allocated memory of size %lu for %d words\n",(words + 1) * sizeof(char*), words + 1);
	if ((split = malloc(sizeof(char *) * (words + 1))))
	{
		k = 0;
		i = 0;
		while (i < words)
		{
			j = 0;
			while (s[k] == c)
				k++;
			printf("Allocated memory of size %lu for word\n", sizeof(char) * (count_char(&s[k], c) + 1));
			if ((split[i] = malloc(sizeof(char) * (count_char(&s[k], c) + 1))))
			{
				while (s[k] != c && s[k] != '\0')
					split[i][j++] = s[k++];
				split[i++][j] = '\0';
			}
		}
		split[i] = NULL;
	}
	return (split);
}
