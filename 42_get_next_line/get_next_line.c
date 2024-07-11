/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:42:55 by alibourb          #+#    #+#             */
/*   Updated: 2023/01/10 16:21:36 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Contraintes du projet :
- compiler avec les 3W.
- lecture ligne par ligne (donc arret strchr sur \n).
- retour nul ou erreur de la fonction GNL est NULL.
- la ligne retournee DOIT inclure un \n final, SAUF a la fin, 
ne rien ajouter donc a \0.
- ajouter -D BUFFER_SIZE=n lors de la compilation, commande pour la fonction 
read : "cc -Wall -Wextra -Werror -D BUFFER_SIZE=42"
*/

#include "get_next_line.h"

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
	temp = (char *)malloc(sizeof(*temp) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free (stash);
	return (temp);
}

// si pas de \n dans la stash, on est en fin de texte, donc inutile de renew.
// incrementation pour passer le \n et commencer dans le morceau a stash.
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = stash_to_line(stash);
	stash = renew_stash(stash);
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
