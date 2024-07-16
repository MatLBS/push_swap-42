/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:26:30 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/11 11:08:47 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_free_line(char *str, char *str2)
{
	if (str != NULL)
		free(str);
	if (str2 == NULL)
		return (NULL);
	free(str2);
	return (NULL);
}

char	*fill_stash(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	int		bytes_read;

	bytes_read = 0;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (ft_free_line(stash, NULL));
	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_free_line(buff, stash));
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
		if (stash == NULL)
			return (ft_free_line(buff, NULL));
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stash);
}

char	*fill_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	line[i] = '\0';
	i--;
	while (i >= 0)
	{
		line[i] = stash[i];
		i--;
	}
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (ft_strchr(stash, '\0'))
		return (ft_free_line(stash, 0));
	tmp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (tmp == NULL)
		return (ft_free_line(stash, NULL));
	i++;
	j = 0;
	while (stash[i] != '\0')
		tmp[j++] = stash[i++];
	tmp[j] = '\0';
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_calloc(1, sizeof(char));
	if (stash == NULL)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = fill_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
