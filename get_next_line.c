/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:44:52 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/03 15:11:23 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_read_front(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		dest[i++] = '\n';
	return (dest);
}

char	*ft_read_back(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	dest = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	while (str[i])
		dest[j++] = str[++i];
	free(str);
	return (dest);
}

char	*ft_free(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == 0)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (i > 0 && !(ft_strchr(buffer, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_free(str, buffer);
	}
	free(buffer);
	return (line = ft_read_front(str), str = ft_read_back(str), line);
}

int main()
{
	int	i;
	int	fd;
	char *str;

	fd = open("Celine.txt", O_RDONLY);
	i = 0;
 	while(i < 50)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
}