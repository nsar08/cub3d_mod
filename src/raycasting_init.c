/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:49:58 by nsar              #+#    #+#             */
/*   Updated: 2022/12/05 13:36:56 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/cub3d.h"

void	ft_initialisation2(t_recup *recup)
{
	recup->s.ZBuffer = (double *)malloc(sizeof(double) * recup->Rx);
	if (!(recup->s.ZBuffer))
		exit(0);
	recup->data.forward = 0;
	recup->data.back = 0;
	recup->data.left = 0;
	recup->data.right = 0;
	recup->data.rotate_right = 0;
	recup->data.rotate_left = 0;
	recup->ray.posX = (double)recup->dx;
	recup->ray.posY = (double)recup->dy;
	recup->ray.dirX = 0;
	recup->ray.dirY = 0;
	recup->ray.planX = 0;
	recup->ray.planY = 0;
	ft_init_dir(recup);
}

void	ft_initialisation3(t_recup *recup)
{
	recup->ray.hit = 0;
	recup->ray.perpWallDist = 0;
	recup->ray.cameraX = 2 * recup->ray.x / (double)recup->Rx - 1;
	//calcul de la position du rayon sur le plan de la camera
	recup->ray.rayDirX = recup->ray.dirX + recup->ray.planX * \
						recup->ray.cameraX; //calcul de direction x du rayon
	recup->ray.rayDirY = recup->ray.dirY + recup->ray.planY * \
						recup->ray.cameraX; //calcul de direction y du rayon
	recup->ray.mapX = (int)recup->ray.posX;
	recup->ray.mapY = (int)recup->ray.posY;
	recup->ray.movespeed = 0.1;
	recup->ray.rotspeed = 0.033 * 1.8;
	ft_init_more3(recup);
}

void	ft_init_texture(t_recup *recup)
{
	if (recup->ray.side == 0 && recup->ray.rayDirX < 0) //NO
		recup->t.texdir = 0;
	if (recup->ray.side == 0 && recup->ray.rayDirX >= 0) // S
		recup->t.texdir = 1;
	if (recup->ray.side == 1 && recup->ray.rayDirY < 0) // WE
		recup->t.texdir = 2;
	if (recup->ray.side == 1 && recup->ray.rayDirY >= 0) // EA
		recup->t.texdir = 3;
	if (recup->ray.side == 0)
		recup->t.wallX = recup->ray.posY + recup->ray.perpWallDist \
						* recup->ray.rayDirY;
	else
		recup->t.wallX = recup->ray.posX + recup->ray.perpWallDist \
						* recup->ray.rayDirX;
	recup->t.wallX -= floor((recup->t.wallX)); // wallX = 15.3 devient wallX = 0.3
}

