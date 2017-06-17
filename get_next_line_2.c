/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 14:49:32 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 17:40:52 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buff_cpy(int i, char *buff)
{
	char	*str;
	int 	j;

	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (0);
	while (j < i)
	{
		str[j] = buff[j];
		j++;
	}
	return (str);
}


int			get_next_line(const int fd, char **line)
{
	static char		*tmp = NULL;
//	char			*r_line;
//	int				nb_read;
	int				i;
	char 			buff[BUFF_SIZE];

//	nb_read = 1;
//	free(&(line));
	while (read(fd, buff, BUFF_SIZE))
	{
		i = 0;
		while (i <  BUFF_SIZE)
		{
			if (buff[i] == '\n')
			{
// copie buff jusqu'a buff[i - 1] dans line
				*line = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(buff) + 1));
				*line = ft_strjoin(tmp, ft_buff_cpy(i, buff));
				free(tmp);
				free(ft_buff_cpy(i, buff));
				tmp = ft_strdup(buff + i);
				return (1);
			}
			else if (buff[i] == '\0')
			{
				*line = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(buff) + 1));
				*line = ft_strjoin(tmp, ft_buff_cpy(i, buff));
				free(ft_buff_cpy(i, buff));
				free(tmp);
				return (1);
			}
			i++;
		}
//		tmp = (char*)malloc(sizeof(char) * BUFF_SIZE * nb_read);
		tmp = ft_strjoin(tmp, buff);
//		nb_read++;
	}
	return (0);
}
