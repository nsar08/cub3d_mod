/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:07:18 by nsar              #+#    #+#             */
/*   Updated: 2022/12/12 17:41:49 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_2(t_recup *recup)
{
	recup->depart = 'x';
	recup->indicateur2 = 0;
	recup->data.img = NULL;
	recup->texture[0].img = NULL;
	recup->texture[1].img = NULL;
	recup->texture[2].img = NULL;
	recup->texture[3].img = NULL;
	recup->texture[4].img = NULL;
	recup->data.mlx_win = NULL;
	recup->map = NULL;
	recup->s.order = NULL;
	recup->s.dist = NULL;
}

void	ft_init_dir(t_recup *recup)
{
	if (recup->depart == 'N')
		recup->ray.dirx = -1;
	if (recup->depart == 'S')
		recup->ray.dirx = 1;
	if (recup->depart == 'E')
		recup->ray.diry = 1;
	if (recup->depart == 'W')
		recup->ray.diry = -1;
	if (recup->depart == 'N')
		recup->ray.plany = 0.66;
	if (recup->depart == 'S')
		recup->ray.plany = -0.66;
	if (recup->depart == 'E')
		recup->ray.planx = 0.66;
	if (recup->depart == 'W')
		recup->ray.planx = -0.66;
}

void	ft_init_more3(t_recup *recup)
{
	if (recup->ray.raydiry == 0)
		recup->ray.deltadistx = 0;
	else if (recup->ray.raydirx == 0)
		recup->ray.deltadistx = 1;
	else
		recup->ray.deltadistx = sqrt(1 + (recup->ray.raydiry \
			* recup->ray.raydiry) / (recup->ray.raydirx * \
			recup->ray.raydirx));
	if (recup->ray.raydirx == 0)
		recup->ray.deltadisty = 0;
	else if (recup->ray.raydiry == 0)
		recup->ray.deltadisty = 1;
	else
		recup->ray.deltadisty = sqrt(1 + (recup->ray.raydirx * \
			recup->ray.raydirx) / (recup->ray.raydiry * \
			recup->ray.raydiry));
}
