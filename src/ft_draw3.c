/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:46 by kzeng             #+#    #+#             */
/*   Updated: 2017/03/23 17:31:48 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_iii_helper(t_list *list, int diff, int int_y, int c)
{
	int		j;
	int		x1;
	int		half;
	int		y1;

	j = 0;
	x1 = list->x - list->i;
	half = diff / 2;
	while (diff > 0)
	{
		j++;
		y1 = int_y + j;
		if (diff <= half)
		{
			if (x1 >= 1 && x1 <= 1201 && y1 >= 0 && y1 <= 1200)
				mlx_pixel_put(list->mlx, list->win, x1 - 1, y1, c);
		}
		if (diff >= half)
		{
			if (x1 >= 0 && x1 <= 1200 && y1 >= 0 && y1 <= 1200)
				mlx_pixel_put(list->mlx, list->win, x1, y1, c);
		}
		diff--;
	}
}

void	ft_draw_iii(t_list *list, int x1, float y1, float dx)
{
	float	i;
	int		int_y;
	int		diff;
	float	inc;
	float	c;

	i = -1;
	while (++i < dx)
	{
		int_y = (y1 + (list->slope * -1 * i));
		inc = dx / (float)(list->next_height - list->curr_height);
		c = ft_color(list, (float)list->curr_height + (i / inc));
		if (x1 - i >= 0 && x1 - i <= 1200 && int_y >= 0 && int_y <= 1200)
			mlx_pixel_put(list->mlx, list->win, x1 - i, int_y, c);
		if ((i > 0 || (list->slope * -1 >= 1.0)) && dx != 0.0)
		{
			list->i = i;
			diff = (y1 + (list->slope * -1 * (i + 1))) - int_y;
			ft_draw_iii_helper(list, diff, int_y, c);
		}
	}
}

void	ft_draw_iv_helper(t_list *list, int diff, int int_y, int c)
{
	int		j;
	int		x1;
	int		half;
	int		y1;

	j = 0;
	x1 = list->x + list->i;
	half = diff / 2;
	while (diff > 0)
	{
		j++;
		y1 = int_y + j;
		if (diff <= half)
		{
			if (x1 >= 0 && x1 <= 1200 && y1 >= 0 && y1 <= 1200)
				mlx_pixel_put(list->mlx, list->win, x1, y1, c);
		}
		if (diff >= half)
		{
			if (x1 >= 0 && x1 <= 1200 && y1 >= 0 && y1 <= 1200)
				mlx_pixel_put(list->mlx, list->win, x1, y1, c);
		}
		diff--;
	}
}

void	ft_draw_iv(t_list *list, int x1, float y1, float dx)
{
	float	i;
	int		int_y;
	int		diff;
	float	inc;
	float	c;

	i = -1;
	while (++i < dx)
	{
		int_y = (y1 + (list->slope * i));
		inc = dx / (float)(list->next_height - list->curr_height);
		c = ft_color(list, (float)list->curr_height + (i / inc));
		if (x1 + i >= 0 && x1 + i <= 1200 && int_y >= 0 && int_y <= 1200)
			mlx_pixel_put(list->mlx, list->win, x1 + i, int_y, c);
		if ((i > 0 || list->slope >= 1.0) && dx != 0.0)
		{
			list->i = i;
			diff = (y1 + (list->slope * (i + 1))) - int_y;
			ft_draw_iv_helper(list, diff, int_y, c);
		}
	}
}
