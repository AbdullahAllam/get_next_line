/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:24:37 by abali             #+#    #+#             */
/*   Updated: 2023/02/09 17:10:47 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_sepline(char *punchstr)
{
	char	*line;
	int		fcounter;

	fcounter = 0;
	if (!punchstr[fcounter])
		return (NULL);
	while (punchstr[fcounter] && punchstr[fcounter] != '\n')
		fcounter++;
	line = malloc(sizeof(char) * (fcounter + 2));
	if (!line)
		return (NULL);
	fcounter = 0;
	while (punchstr[fcounter] != '\n' && punchstr[fcounter] != '\0')
	{
		line[fcounter] = punchstr[fcounter];
		fcounter++;
	}
	if (punchstr[fcounter] == '\n')
		line[fcounter++] = '\n';
	line[fcounter] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*lineptr;
	static char	*punchstr[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	punchstr[fd] = ft_getstr(fd, punchstr[fd]);
	if (!punchstr[fd])
		return (NULL);
	lineptr = ft_sepline(punchstr[fd]);
	punchstr[fd] = ft_getnewstr(punchstr[fd]);
	return (lineptr);
}
/*
int	main(void)
{
	char	*ptr;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd;
	
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		ptr = get_next_line(0);
		printf("The next line is : %s", ptr);
		free(ptr);
		ptr = get_next_line(fd1);
		printf("The next line is : %s", ptr);
		free(ptr);
		ptr = get_next_line(fd2);
		printf("The next line is : %s", ptr);
		free(ptr);
		ptr = get_next_line(fd3);
		printf("The next line is : %s", ptr);
		free(ptr);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
