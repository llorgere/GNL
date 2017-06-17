/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:39:26 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 16:49:22 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char	*str;
//	char	**line;
	int 	j;
	char	**p_line;
	static int		i;
	char	buff[BUFF_SIZE + 1];

//	i = 0;
	while (read(fd, buff, BUFF_SIZE) != 0)
	{
		j = 0;
		buff[BUFF_SIZE] = '\0';
		while (buff[j] != '\0')
		{
			line[i][j] = buff[j];
			if (buff[j] == '\n')
			{  
				while (buff[j] != '\0')
				{
					p_line[i][j] = buff[j];

				}
				i++;
				return (1);
			}
			else if (buff[j] == EOF)
				return (0)
			j++;
		}
		while (j <= BUFF_SIZE)
		{
			p_line[i][j] = buff[j];
			j++;
		}
		i++;
	}
}
