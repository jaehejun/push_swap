/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehejun <jaehejun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:30:12 by jaehejun          #+#    #+#             */
/*   Updated: 2023/09/18 20:41:57 by jaehejun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
