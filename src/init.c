/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:07:18 by nsar              #+#    #+#             */
/*   Updated: 2022/12/05 13:23:19 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void ft_init_2(t_recup *recup)
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
void ft_init_dir(t_recup *recup)
{
    if (recup->depart == 'N')
		recup->ray.dirX = -1;
	if (recup->depart == 'S')
		recup->ray.dirX = 1;
	if (recup->depart == 'E')
		recup->ray.dirY = 1;
	if (recup->depart == 'W')
		recup->ray.dirY = -1;
	if (recup->depart == 'N')
		recup->ray.planY = 0.66;
	if (recup->depart == 'S')
		recup->ray.planY = -0.66;
	if (recup->depart == 'E')
		recup->ray.planX = 0.66;
	if (recup->depart == 'W')
		recup->ray.planX = -0.66;
}

void ft_init_more3(t_recup *recup)
{
    if (recup->ray.rayDirY == 0)
		recup->ray.deltaDistX = 0;
	else if (recup->ray.rayDirX == 0)
		recup->ray.deltaDistX = 1;
	else
		recup->ray.deltaDistX = sqrt(1 + (recup->ray.rayDirY
			* recup->ray.rayDirY) / (recup->ray.rayDirX *
			recup->ray.rayDirX));
	if (recup->ray.rayDirX == 0)
		recup->ray.deltaDistY = 0;
	else if (recup->ray.rayDirY == 0)
		recup->ray.deltaDistY = 1;
	else
		recup->ray.deltaDistY = sqrt(1 + (recup->ray.rayDirX *
			recup->ray.rayDirX) / (recup->ray.rayDirY *
			recup->ray.rayDirY));
            /*recup->ray.deltaDistX = (recup->ray.rayDirY == 0) ? 0 : ((recup->ray.rayDirX == 0) ? 1 : sqrt(1 + (recup->ray.rayDirY * \
			recup->ray.rayDirY) / (recup->ray.rayDirX * recup->ray.rayDirX)));//deltaDistX and deltaDistY are the distance the ray has to travel to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
	recup->ray.deltaDistY = (recup->ray.rayDirX == 0) ? 0 : \
			((recup->ray.rayDirY == 0) ? 1 : sqrt(1 + (recup->ray.rayDirX * recup->ray.rayDirX) / (recup->ray.rayDirY * recup->ray.rayDirY)));//pas le droit ternaire*/
}