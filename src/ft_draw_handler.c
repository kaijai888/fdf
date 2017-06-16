/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:46 by kzeng             #+#    #+#             */
/*   Updated: 2017/03/23 17:31:48 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_list *list, float height)
{
	if (height > list->min_height)
	{
		if (height <= ((float)list->range * 0.10))
			return (0x00F8C325);
		else if (height <= ((float)list->range * 0.20))
			return (0x00F89D25);
		else if (height <= ((float)list->range * 0.30))
			return (0x00F87D25);
		else if (height <= ((float)list->range * 0.40))
			return (0x00F86125);
		else if (height <= ((float)list->range * 0.50))
			return (0x00F83E25);
		else if (height <= ((float)list->range * 0.60))
			return (0x00F825A0);
		else if (height <= ((float)list->range * 0.70))
			return (0x00F825E7);
		else if (height <= ((float)list->range * 0.80))
			return (0x00CE25F8);
		else if (height <= ((float)list->range * 0.90))
			return (0x009625F8);
		else if (height <= (float)list->range)
			return (0x00A725F8);
	}
	return (0x00FFFFFF);
}

void	ft_draw_helper(t_list *list, int i, int j)
{
	int		s1;
	int		s2;

	list->curr_height = list->map[i][j];
	s1 = (list->map[i][j] - list->min_height) * list->px_height;
	if (j < list->width - 1)
	{
		list->next_height = list->map[i][j + 1];
		s2 = (list->map[i][j + 1] - list->min_height) * list->px_height;
		if (list->map[i][j] - list->map[i][j + 1] == 0)
			ft_draw_line(list, 1, s1, s2);
		else
			ft_draw_line(list, 2, s1, s2);
	}
	if (i < list->length - 1)
	{
		list->next_height = list->map[i + 1][j];
		s2 = (list->map[i + 1][j] - list->min_height) * list->px_height;
		if (list->map[i][j] - list->map[i + 1][j] == 0)
			ft_draw_line(list, 3, s1, s2);
		else
			ft_draw_line(list, 4, s1, s2);
	}
}

void	ft_draw(t_list *list)
{
	int		i;
	int		j;
	int		z;

	if (list->error < 0)
		return ;
	i = -1;
	z = ((list->range * 2) + (i * list->draw) > 1050) ? 0 : list->range * 2;
	while (++i < list->length)
	{
		list->x = (((list->width * list->draw) + 10) - (i * list->draw));
		if (list->length > list->width)
			list->x += ((list->length - list->width) * list->draw);
		else if (list->length < list->width)
			list->x -= ((list->width - list->length) * list->draw);
		list->y = 100 + z + (i * list->draw);
		j = -1;
		while (++j < list->width)
		{
			ft_draw_helper(list, i, j);
			list->x += list->draw;
			list->y += list->draw;
		}
	}
}

void	ft_click_draw(t_list *list, int x, int y)
{
	int		i;
	int		j;

	if (list->error < 0)
		return ;
	i = -1;
	while (++i < list->length)
	{
		list->x = x - (i * list->draw);
		list->y = y + (i * list->draw);
		j = -1;
		while (++j < list->width)
		{
			ft_draw_helper(list, i, j);
			list->x += list->draw;
			list->y += list->draw;
		}
	}
}

void	ft_draw_handler(t_list *list)
{
	ft_draw(list);
	mlx_hook(list->win, 2, 0, key_hook, list);
	mlx_mouse_hook(list->win, mouse_hook, list);
	mlx_loop(list->mlx);
}
