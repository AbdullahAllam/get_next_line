/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:57:36 by abali             #+#    #+#             */
/*   Updated: 2023/02/09 16:30:23 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strln(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strln(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *punchstr, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!punchstr)
	{
		punchstr = (char *)malloc(1 * sizeof(char));
		punchstr[0] = '\0';
	}
	if (!punchstr || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strln(punchstr) + ft_strln(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (punchstr)
		while (punchstr[++i] != '\0')
			str[i] = punchstr[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strln(punchstr) + ft_strln(buffer)] = '\0';
	free(punchstr);
	return (str);
}

char	*ft_getstr(int fd, char *punchstr)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(punchstr, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		punchstr = ft_strjoin(punchstr, buffer);
	}
	free(buffer);
	return (punchstr);
}

char	*ft_getnewstr(char *punchstr)
{
	char	*newpunchstr;
	int		fcounter;
	int		scounter;

	fcounter = 0;
	scounter = 0;
	while (punchstr[fcounter] && punchstr[fcounter] != '\n')
		fcounter++;
	if (!punchstr[fcounter]
		|| (punchstr[fcounter] == '\n' && !punchstr[fcounter + 1]))
	{
		free(punchstr);
		return (NULL);
	}	
	newpunchstr = malloc(sizeof(char) * (ft_strln(punchstr) - fcounter + 1));
	if (!newpunchstr)
		return (NULL);
	fcounter++;
	while (punchstr[fcounter])
		newpunchstr[scounter++] = punchstr[fcounter++];
	newpunchstr[scounter] = '\0';
	free(punchstr);
	return (newpunchstr);
}
