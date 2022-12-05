/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:28 by nsar              #+#    #+#             */
/*   Updated: 2022/12/05 13:05:56 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    ft_forward_back(t_recup *recup)
{
    if (recup->data.forward == 1)//move forward if no wall in front of you
	{
		if (recup->map[(int)(recup->ray.posX + recup->ray.dirX \
		* recup->ray.movespeed)][(int)recup->ray.posY] == '0')
			recup->ray.posX += recup->ray.dirX * recup->ray.movespeed;
		if (recup->map[(int)(recup->ray.posX)][(int)(recup->ray.posY \
		+ recup->ray.dirY * recup->ray.movespeed)] == '0') 
			recup->ray.posY += recup->ray.dirY * recup->ray.movespeed;
	}
    if (recup->data.back == 1)//move backwards if no wall behind you
	{
		if (recup->map[(int)(recup->ray.posX - recup->ray.dirX \
		* recup->ray.movespeed)][(int)(recup->ray.posY)] == '0') 
			recup->ray.posX -= recup->ray.dirX * recup->ray.movespeed;
		if (recup->map[(int)(recup->ray.posX)][(int)(recup->ray.posY \
		- recup->ray.dirY * recup->ray.movespeed)] == '0') 
			recup->ray.posY -= recup->ray.dirY * recup->ray.movespeed;
	}
}

void	ft_left_right(t_recup *recup)
{
	if (recup->data.right == 1)//both camera DIRECTION and camera plane must be rotated
	{
		if (recup->map[(int)(recup->ray.posX + recup->ray.dirY * \
					recup->ray.movespeed)][(int)recup->ray.posY] == '0')
			recup->ray.posX += recup->ray.dirY * recup->ray.movespeed;
		if (recup->map[(int)recup->ray.posX][(int)(recup->ray.posY - \
		recup->ray.dirX * recup->ray.movespeed)] == '0')
			recup->ray.posY -=  recup->ray.dirX * recup->ray.movespeed;
	}
	if (recup->data.left == 1)
	{
		if (recup->map[(int)(recup->ray.posX - recup->ray.dirY * \
					recup->ray.movespeed)][(int)recup->ray.posY] == '0')
			recup->ray.posX -= recup->ray.dirY * recup->ray.movespeed;
		if (recup->map[(int)recup->ray.posX][(int)(recup->ray.posY \
		+ recup->ray.dirX * recup->ray.movespeed)] == '0')
			recup->ray.posY +=  recup->ray.dirX * recup->ray.movespeed;
	}
}

void    ft_rotate_right_left(t_recup *recup)
{
	double oldDirX;
	double oldPlanX;
	
	oldPlanX = recup->ray.planX;
	oldDirX = recup->ray.dirX;
    if (recup->data.rotate_right == 1)//both camera direction and camera PLANE must be rotated
	{
		recup->ray.dirX = recup->ray.dirX * cos(-recup->ray.rotspeed / 2) \
		- recup->ray.dirY * sin(-recup->ray.rotspeed / 2);
		recup->ray.dirY = oldDirX * sin(-recup->ray.rotspeed / 2) \
		+ recup->ray.dirY * cos(-recup->ray.rotspeed / 2);
		recup->ray.planX = recup->ray.planX * cos(-recup->ray.rotspeed / 2) \
		- recup->ray.planY * sin(-recup->ray.rotspeed / 2);
		recup->ray.planY = oldPlanX * sin(-recup->ray.rotspeed / 2) \
		+ recup->ray.planY * cos(-recup->ray.rotspeed / 2);
	}
	ft_rotate_left(recup, oldDirX);
}

void ft_rotate_left(t_recup *recup, double oldDirX)
{
	double oldPlaneX;

	if (recup->data.rotate_left == 1)
	{
		oldDirX = recup->ray.dirX;
		oldPlaneX = recup->ray.planX;
		recup->ray.dirX = recup->ray.dirX * cos(recup->ray.rotspeed / 2) \
		- recup->ray.dirY * sin(recup->ray.rotspeed / 2);
		recup->ray.dirY = oldDirX * sin(recup->ray.rotspeed / 2) \
		+ recup->ray.dirY * cos(recup->ray.rotspeed / 2);
		recup->ray.planX = recup->ray.planX * cos(recup->ray.rotspeed / 2) \
		- recup->ray.planY * sin(recup->ray.rotspeed / 2);
		recup->ray.planY = oldPlaneX * sin(recup->ray.rotspeed / 2) \
		+ recup->ray.planY * cos(recup->ray.rotspeed / 2);
	}
}
