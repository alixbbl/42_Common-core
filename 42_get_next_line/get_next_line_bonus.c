/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:42:55 by alibourb          #+#    #+#             */
/*   Updated: 2023/01/10 16:32:03 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_stash(int fd, char *stash)
{
	int		len_buffer;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len_buffer = 1;
	while (len_buffer != 0 && !(ft_strchr(stash, '\n')))
	{
		len_buffer = read(fd, buffer, BUFFER_SIZE);
		if (len_buffer == -1)
		{
			free(buffer);
			if (stash)
				free (stash);
			return (NULL);
		}
		buffer[len_buffer] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*stash_to_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc((sizeof(*line) * (i + 2)));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		line[j++] = stash[i++];
	if (stash[i] == '\n')
		line[j++] = stash[i++];
	line[j] = '\0';
	return (line);
}

char	*renew_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		return (NULL);
	}
	temp = malloc(sizeof(*temp) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free (stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = stash_to_line(stash[fd]);
	stash[fd] = renew_stash(stash[fd]);
	return (line);
}

// #include <fcntl.h>
// #include "get_next_line.h"

// int main()
// {
//  char *str;
//  int fd1 = open("text1.txt", O_RDONLY);
//  while (1)
//  {
// 	str = get_next_line(fd1);
//  	printf("%s", str);
// 	if (!str)
// 		break;
// 	free(str);
// 	close(fd1);
//  }
//  free(str);
//  return (0);
// }