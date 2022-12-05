/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:41 by nsar              #+#    #+#             */
/*   Updated: 2022/12/05 16:38:26 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int check_map(t_recup *recup)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (recup->map[i][j] != '\0')
	{
		if (recup->map[i][j] != ' ' && recup->map[i][j] != '0' && recup->map[i][j] != '1' \
			&& recup->map[i][j] != '\t' && recup->map[i][j] != 'N' && recup->map[i][j] != 'S' \
			&& recup->map[i][j] != 'E' && recup->map[i][j] != 'W' && recup->map[i][j] != '\n')
			{
				exit(1);
			}
			else
			{
				i++;
			}
		j++;
	}
	return(0);
}

int		ft_murs(t_recup *recup)//check que la map soit entouree de murs
{
	int i;

	i = 0;
	while (i < recup->nblines)
	{
		if (recup->map[i][0] != '1')//check premiere colonne
			return (1);
		i++;
	}
	i = 0;
	while (i < recup->nblines)
	{
		if (recup->map[i][recup->sizeline - 1] != '1')//derniere colonne
			return (1);
		i++;
	}
	if (ft_murs_util(recup->map[0]) == 1)//premiere ligne
		return (1);
	if (ft_murs_util(recup->map[recup->nblines - 1]) == 1)//derniere ligne
		return (1);
	return (0);
}

int		ft_copy_map(char *str, t_recup *recup)
{
	static int	i = 0;
	int			j;

	j = 0;
	recup->map[i] = NULL;
	if (!(recup->map[i] = malloc(sizeof(char) * recup->sizeline + 1)))
		return (0);
	while (str[j] != '\0')
	{
		if (ft_depart(str[j], recup, i, j) == 1)
			recup->map[i][j] = '0';
		else if (str[j] == ' ')
			recup->map[i][j] = '1';
		else
			recup->map[i][j] = str[j];
		j++;
	}
	while (j <= (recup->sizeline - 1))
	{
		recup->map[i][j] = '1';
		j++;
	}
	recup->map[i][j] = '\0';
	i++;
	//check_map(recup);
	return (0);
}

int		ft_is_map(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
					&& str[i] != '\t' && str[i] != 'N' && str[i] != 'S' \
					&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n')
				return(0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_recup *recup)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str) == 1)
	{
		if ((i = ft_strlen(str)) > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	recup->nblines = snblines;
	recup->sizeline = ssizeline;
}
