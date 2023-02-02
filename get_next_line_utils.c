/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:45:00 by abonnefo          #+#    #+#             */
/*   Updated: 2022/12/13 13:23:25 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strlcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strlcat(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;

	i = 0;
	dst_size = ft_strlen(dst);
	i = dst_size;
	j = 0;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	tab = malloc(nmemb * size);
	if (tab == 0)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;

	if (s1 == 0)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == 0)
			return (NULL);
		s1[0] = '\0';
	}
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == 0 || s1 == 0 || s2 == 0)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(dst, s1);
	ft_strlcat(dst, s2);
	return (dst);
}
