/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:24:37 by abali             #+#    #+#             */
/*   Updated: 2023/02/09 16:31:32 by abali            ###   ########.fr       */
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
	static char	*punchstr;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	punchstr = ft_getstr(fd, punchstr);
	if (!punchstr)
		return (NULL);
	lineptr = ft_sepline(punchstr);
	punchstr = ft_getnewstr(punchstr);
	return (lineptr);
}

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("test.txt", O_RDONLY);
	ptr = get_next_line(0);
	printf("The next line is : %s", ptr);
	free (ptr);
	ptr = get_next_line(fd);
	printf("The next line is : %s", ptr);
	free (ptr);
	ptr = get_next_line(fd);
	printf("The next line is : %s", ptr);
	free (ptr);
	ptr = get_next_line(fd);
	printf("The next line is : %s", ptr);
	free (ptr);
	ptr = get_next_line(fd);
	printf("The next line is : %s", ptr);
	free (ptr);
	close (fd);
	return (0);
}
