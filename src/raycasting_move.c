/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:28 by nsar              #+#    #+#             */
/*   Updated: 2022/12/12 17:51:33 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_forward_back(t_recup *recup)
{
	if (recup->data.forward == 1) //move forward if no wall in front of you
	{
		if (recup->map[(int)(recup->ray.posx + recup->ray.dirx \
		* recup->ray.movespeed)][(int)recup->ray.posy] == '0')
			recup->ray.posx += recup->ray.dirx * recup->ray.movespeed;
		if (recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy \
		+ recup->ray.diry * recup->ray.movespeed)] == '0')
			recup->ray.posy += recup->ray.diry * recup->ray.movespeed;
	}
	if (recup->data.back == 1) //move backwards if no wall behind you
	{
		if (recup->map[(int)(recup->ray.posx - recup->ray.dirx \
		* recup->ray.movespeed)][(int)(recup->ray.posy)] == '0')
			recup->ray.posx -= recup->ray.dirx * recup->ray.movespeed;
		if (recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy \
		- recup->ray.diry * recup->ray.movespeed)] == '0')
			recup->ray.posy -= recup->ray.diry * recup->ray.movespeed;
	}
}

void	ft_left_right(t_recup *recup)
{
	if (recup->data.right == 1)
	{
		if (recup->map[(int)(recup->ray.posx + recup->ray.diry * \
					recup->ray.movespeed)][(int)recup->ray.posy] == '0')
			recup->ray.posx += recup->ray.diry * recup->ray.movespeed;
		if (recup->map[(int)recup->ray.posx][(int)(recup->ray.posy - \
		recup->ray.dirx * recup->ray.movespeed)] == '0')
			recup->ray.posy -= recup->ray.dirx * recup->ray.movespeed;
	}
	if (recup->data.left == 1)
	{
		if (recup->map[(int)(recup->ray.posx - recup->ray.diry * \
					recup->ray.movespeed)][(int)recup->ray.posy] == '0')
			recup->ray.posx -= recup->ray.diry * recup->ray.movespeed;
		if (recup->map[(int)recup->ray.posx][(int)(recup->ray.posy \
		+ recup->ray.dirx * recup->ray.movespeed)] == '0')
			recup->ray.posy += recup->ray.dirx * recup->ray.movespeed;
	}
}

void	ft_rotate_right_left(t_recup *recup)
{
	double	olddirx;
	double	oldplanx;

	oldplanx = recup->ray.planx;
	olddirx = recup->ray.dirx;
	if (recup->data.rotate_right == 1) //both camera direction and camera PLANE must be rotated
	{
		recup->ray.dirx = recup->ray.dirx * cos(-recup->ray.rotspeed / 2) \
		- recup->ray.diry * sin(-recup->ray.rotspeed / 2);
		recup->ray.diry = olddirx * sin(-recup->ray.rotspeed / 2) \
		+ recup->ray.diry * cos(-recup->ray.rotspeed / 2);
		recup->ray.planx = recup->ray.planx * cos(-recup->ray.rotspeed / 2) \
		- recup->ray.plany * sin(-recup->ray.rotspeed / 2);
		recup->ray.plany = oldplanx * sin(-recup->ray.rotspeed / 2) \
		+ recup->ray.plany * cos(-recup->ray.rotspeed / 2);
	}
	ft_rotate_left(recup, olddirx);
}

void	ft_rotate_left(t_recup *recup, double olddirx)
{
	double	oldplanex;

	if (recup->data.rotate_left == 1)
	{
		olddirx = recup->ray.dirx;
		oldplanex = recup->ray.planx;
		recup->ray.dirx = recup->ray.dirx * cos(recup->ray.rotspeed / 2) \
		- recup->ray.diry * sin(recup->ray.rotspeed / 2);
		recup->ray.diry = olddirx * sin(recup->ray.rotspeed / 2) \
		+ recup->ray.diry * cos(recup->ray.rotspeed / 2);
		recup->ray.planx = recup->ray.planx * cos(recup->ray.rotspeed / 2) \
		- recup->ray.plany * sin(recup->ray.rotspeed / 2);
		recup->ray.plany = oldplanex * sin(recup->ray.rotspeed / 2) \
		+ recup->ray.plany * cos(recup->ray.rotspeed / 2);
	}
}
