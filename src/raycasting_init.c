/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:49:58 by nsar              #+#    #+#             */
/*   Updated: 2022/12/12 17:55:26 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_initialisation2(t_recup *recup)
{
	recup->s.zbuffer = (double *)malloc(sizeof(double) * recup->rx);
	if (!(recup->s.zbuffer))
		exit(0);
	recup->data.forward = 0;
	recup->data.back = 0;
	recup->data.left = 0;
	recup->data.right = 0;
	recup->data.rotate_right = 0;
	recup->data.rotate_left = 0;
	recup->ray.posx = (double)recup->dx;
	recup->ray.posy = (double)recup->dy;
	recup->ray.dirx = 0;
	recup->ray.diry = 0;
	recup->ray.planx = 0;
	recup->ray.plany = 0;
	ft_init_dir(recup);
}

void	ft_initialisation3(t_recup *recup)
{
	recup->ray.hit = 0;
	recup->ray.perpwalldist = 0;
	recup->ray.camerax = 2 * recup->ray.x / (double)recup->rx - 1;
	//calcul de la position du rayon sur le plan de la camera
	recup->ray.raydirx = recup->ray.dirx + recup->ray.planx * \
						recup->ray.camerax; //calcul de direction x du rayon
	recup->ray.raydiry = recup->ray.diry + recup->ray.plany * \
						recup->ray.camerax; //calcul de direction y du rayon
	recup->ray.mapx = (int)recup->ray.posx;
	recup->ray.mapy = (int)recup->ray.posy;
	recup->ray.movespeed = 0.1;
	recup->ray.rotspeed = 0.033 * 1.8;
	ft_init_more3(recup);
}

void	ft_init_texture(t_recup *recup)
{
	if (recup->ray.side == 0 && recup->ray.raydirx < 0) //NO
		recup->t.texdir = 0;
	if (recup->ray.side == 0 && recup->ray.raydirx >= 0) // S
		recup->t.texdir = 1;
	if (recup->ray.side == 1 && recup->ray.raydiry < 0) // WE
		recup->t.texdir = 2;
	if (recup->ray.side == 1 && recup->ray.raydiry >= 0) // EA
		recup->t.texdir = 3;
	if (recup->ray.side == 0)
		recup->t.wallx = recup->ray.posy + recup->ray.perpwalldist \
						* recup->ray.raydiry;
	else
		recup->t.wallx = recup->ray.posx + recup->ray.perpwalldist \
						* recup->ray.raydirx;
	recup->t.wallx -= floor((recup->t.wallx)); // wallX = 15.3 devient wallX = 0.3
}
