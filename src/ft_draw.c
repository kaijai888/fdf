/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:46 by kzeng             #+#    #+#             */
/*   Updated: 2017/03/23 17:31:48 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_list *list, int c, int s1, int s2)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	x1 = list->x;
	y1 = list->y - s1;
	x2 = c <= 2 ? list->x + list->draw : list->x - list->draw;
	y2 = c % 2 == 0 ? list->y - s2 + list->draw : list->y - s1 + list->draw;
	list->slope = 0.0;
	if (x1 - x2 != 0)
		list->slope = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
	if (x1 - x2 == 0 || y1 - y2 == 0)
		ft_draw_flat(list, y1, x2, y2);
	else if (list->slope != 0.0)
	{
		if (x1 - x2 < 0 && y1 - y2 > 0)
			ft_draw_i(list, x1, (float)y1, (float)(x2 - x1));
		else if (x1 - x2 > 0 && y1 - y2 > 0)
			ft_draw_ii(list, x1, (float)y1, (float)(x1 - x2));
		else if (x1 - x2 > 0 && y1 - y2 < 0)
			ft_draw_iii(list, x1, (float)y1, (float)(x1 - x2));
		else if (x1 - x2 < 0 && y1 - y2 < 0)
			ft_draw_iv(list, x1, (float)y1, (float)(x2 - x1));
	}
}

int		ft_draw_flat_helper(t_list *list, int y1, int x2, int y2)
{
	int		x1;
	float	i;

	x1 = list->x;
	i = 0;
	if (x1 - x2 == 0 && y1 - y2 < 0)
	{
		while (++y1 <= y2)
		{
			if (x1 >= 0 && x1 <= 1200 && y1 >= 1 && y1 <= 1201)
				mlx_pixel_put(list->mlx, list->win, x1, y1 - 1, 0x00FFFFFF);
		}
		return (1);
	}
	else if (x1 - x2 == 0 && y1 - y2 > 0)
	{
		while (--y1 >= y2)
		{
			if (x1 >= 0 && x1 <= 1200 && y1 >= -1 && y1 <= 1199)
				mlx_pixel_put(list->mlx, list->win, x1, y1 + 1, 0x00FFFFFF);
		}
		return (1);
	}
	return (0);
}

int		ft_draw_flat_helper2(t_list *list, int y1, int x2, int y2)
{
	int		x1;
	float	i;
	int		xdist;
	float	inc;
	float	color;

	x1 = list->x;
	i = 0;
	xdist = x1 - x2 < 0 ? x2 - x1 : x1 - x2;
	if (y1 - y2 == 0 && x1 - x2 < 0)
	{
		inc = (float)xdist / (float)(list->next_height - list->curr_height);
		while (++x1 <= x2)
		{
			color = ft_color(list, (float)list->curr_height + (i / inc));
			if (x1 >= 1 && x1 <= 1201 && y1 >= 0 && y1 <= 1200)
				mlx_pixel_put(list->mlx, list->win, x1 - 1, y1, color);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_draw_flat(t_list *list, int y1, int x2, int y2)
{
	int		x1;
	float	i;
	int		xdist;
	float	inc;
	float	color;

	x1 = list->x;
	i = 0;
	xdist = x1 - x2 < 0 ? x2 - x1 : x1 - x2;
	if (ft_draw_flat_helper(list, y1, x2, y2) == 1)
		return ;
	if (ft_draw_flat_helper2(list, y1, x2, y2) == 1)
		return ;
	if (y1 - y2 == 0 && x1 - x2 > 0)
	{
		inc = (float)xdist / (float)(list->next_height - list->curr_height);
		while (--x1 >= x2)
		{
			color = ft_color(list, (float)list->curr_height + (i / inc));
			if (x1 >= -1 && x1 <= 1199 && y1 >= 0 && y1 <= 1200)
				mlx_pixel_put(list->mlx, list->win, x1 + 1, y1, color);
			i++;
		}
	}
}
